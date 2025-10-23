/*
 * File: 3-cp.c
 * Auth: (Your Name)
 * Desc: A program that copies the content of a file to another file.
 */

#include <stdio.h>    /* For dprintf */
#include <stdlib.h>   /* For exit */
#include <fcntl.h>    /* For open, O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC */
#include <unistd.h>   /* For read, write, close, STDERR_FILENO */
#include <sys/types.h> /* POSIX types */
#include <sys/stat.h>  /* For mode constants (S_IRUSR, etc.) */

/**
 * close_check - Helper function to close a file descriptor and check for errors.
 * @fd: The file descriptor to close.
 *
 * Description: If close() fails, it prints an error message to STDERR
 * and exits with code 100.
 */
void close_check(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Entry point of the program. Copies file_from to file_to.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 * Exits with 97, 98, 99, or 100 on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];
	/* Permissions for new file: rw-rw-r-- (0664) */
	mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	/* 1. Check argument count */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* 2. Open source file (file_from) for reading */
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* 3. Open/Create destination file (file_to) for writing */
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, permissions);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_check(fd_from); /* Must close the first file before exiting */
		exit(99);
	}

	/* 4. Read/Write loop */
	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close_check(fd_from);
			close_check(fd_to);
			exit(99);
		}
	}

	/* 5. Check for a read error (if loop exited because read returned -1) */
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_check(fd_from);
		close_check(fd_to);
		exit(98);
	}

	/* 6. Close both files, checking for errors */
	close_check(fd_from);
	close_check(fd_to);

	return (0);
}

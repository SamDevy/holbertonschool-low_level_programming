/* 3-cp.c */
/**
 * print_usage_and_exit - Prints usage to stderr and exits with code 97
 * @prog: program name
 *
 * Return: Nothing (exits)
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

static void print_usage_and_exit(const char *prog)
{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", prog);
	exit(97);
}

/**
 * error_read_and_exit - Prints read error and exits with code 98
 * @file: file_from name
 *
 * Return: Nothing (exits)
 */
static void error_read_and_exit(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * error_write_and_exit - Prints write error and exits with code 99
 * @file: file_to name
 *
 * Return: Nothing (exits)
 */
static void error_write_and_exit(const char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * close_or_exit - Closes fd or exits with code 100 on failure
 * @fd: file descriptor to close
 *
 * Return: Nothing (exits on error)
 */
static void close_or_exit(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies content of file_from to file_to
 * @argc: argument count
 * @argv: argument vector (argv[1]=file_from, argv[2]=file_to)
 *
 * Return: 0 on success; exits with specific codes on errors
 *
 * Notes:
 * - Reads in 1024-byte chunks.
 * - file_to: O_WRONLY|O_CREAT|O_TRUNC with 0664 perms.
 * - On any read error → 98; write/create error → 99; bad args → 97; close error → 100.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t nread, nwritten;
	char buf[1024];

	if (argc != 3)
		print_usage_and_exit(argv[0]);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_read_and_exit(argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_or_exit(fd_from);
		error_write_and_exit(argv[2]);
	}

	while (1)
	{
		nread = read(fd_from, buf, sizeof(buf));
		if (nread == 0)
			break;
		if (nread < 0)
		{
			close_or_exit(fd_from);
			close_or_exit(fd_to);
			error_read_and_exit(argv[1]);
		}

		/* handle partial writes */
		ssize_t off = 0;
		while (off < nread)
		{
			nwritten = write(fd_to, buf + off, (size_t)(nread - off));
			if (nwritten <= 0)
			{
				close_or_exit(fd_from);
				close_or_exit(fd_to);
				error_write_and_exit(argv[2]);
			}
			off += nwritten;
		}
	}

	close_or_exit(fd_from);
	close_or_exit(fd_to);
	return (0);
}

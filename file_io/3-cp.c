/* 3-cp.c */
/**
 * main - Copies content of file_from to file_to
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exits with 97/98/99/100 on error
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

static void xclose(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	char buf[1024];
	ssize_t nread;
	ssize_t nwritten;
	ssize_t off;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		xclose(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while (1)
	{
		nread = read(fd_from, buf, sizeof(buf));
		if (nread == 0)
			break;
		if (nread < 0)
		{
			xclose(fd_from);
			xclose(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}

		off = 0;
		while (off < nread)
		{
			nwritten = write(fd_to, buf + off, (size_t)(nread - off));
			if (nwritten <= 0)
			{
				xclose(fd_from);
				xclose(fd_to);
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				exit(99);
			}
			off += nwritten;
		}
	}

	xclose(fd_from);
	xclose(fd_to);
	return (0);
}

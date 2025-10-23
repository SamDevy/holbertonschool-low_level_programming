/* 0-read_textfile.c */
/**
 * read_textfile - Reads a text file and prints it to POSIX stdout
 * @filename: path to file
 * @letters: number of bytes to read and print
 *
 * Return: actual number of bytes printed; 0 on any failure
 *
 * Behavior:
 * - Opens filename O_RDONLY.
 * - Allocates buffer of size letters.
 * - Reads up to letters, writes exactly that many to STDOUT_FILENO.
 * - If open/read/write/alloc fails or short write, returns 0.
 * - Always closes file and frees buffer.
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread, nwritten;
	char *buf;

	if (filename == (const char *)0 || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = (char *)malloc(letters);
	if (buf == (char *)0)
	{
		close(fd);
		return (0);
	}

	nread = read(fd, buf, letters);
	if (nread <= 0)
	{
		free(buf);
		close(fd);
		return (0);
	}

	nwritten = write(STDOUT_FILENO, buf, nread);
	if (nwritten != nread)
	{
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);
	return (nwritten);
}

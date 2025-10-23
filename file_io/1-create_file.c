/* 1-create_file.c */
/**
 * create_file - Creates a file and writes a NULL-terminated string to it
 * @filename: name of the file to create
 * @text_content: content to write (may be NULL for empty file)
 *
 * Return: 1 on success, -1 on failure
 *
 * Notes:
 * - Permissions: rw------- (0600). If file exists, truncate but don’t change perms.
 * - Returns -1 if filename is NULL, open/write fails, or any error occurs.
 */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int create_file(const char *filename, char *text_content)
{
	int fd, flags;
	mode_t perms;
	ssize_t len = 0, nw;

	if (filename == (const char *)0)
		return (-1);

	flags = O_CREAT | O_WRONLY | O_TRUNC;
	perms = 0600;

	fd = open(filename, flags, perms);
	if (fd == -1)
		return (-1);

	if (text_content != (char *)0)
	{
		while (text_content[len] != '\0')
			len++;

		nw = write(fd, text_content, (size_t)len);
		if (nw != len)
		{
			close(fd);
			return (-1);
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}

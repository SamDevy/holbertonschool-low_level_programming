/* 2-append_text_to_file.c */
/**
 * append_text_to_file - Appends a NULL-terminated string at file end
 * @filename: name of the file
 * @text_content: text to append (may be NULL: append nothing)
 *
 * Return: 1 on success, -1 on failure
 *
 * Notes:
 * - Do not create the file if it does not exist.
 * - If filename is NULL return -1.
 * - If text_content is NULL, return 1 if file exists and is writable,
 *   otherwise -1.
 */
#include <unistd.h>
#include <fcntl.h>

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len = 0, nw;

	if (filename == (const char *)0)
		return (-1);

	/* Open existing file for append only; do not create */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content == (char *)0)
	{
		/* Nothing to add; file exists and opened successfully */
		close(fd);
		return (1);
	}

	while (text_content[len] != '\0')
		len++;

	nw = write(fd, text_content, (size_t)len);
	if (nw != len)
	{
		close(fd);
		return (-1);
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}

#include "main.h"

/**
 * create_file- function that creates a file
 * @filename: name of the file to create
 * @text_content: a NULL terminated string
 *
 * Return: 1 on success,
 * -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int rwr;
	int nl;

	if (!filename)
	return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
	return (-1);
	if (!text_content)
	text_content = "";

	for (nl = 0; text_content[nl]; nl++)
		;
	rwr = write(fd, text_content, nl);

	if (rwr == -1)
	return (-1);

	close(fd);

	return (1);
}

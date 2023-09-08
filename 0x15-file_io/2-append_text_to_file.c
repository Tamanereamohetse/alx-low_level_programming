#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: is the name of the file
 * @text_content: is the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_d;
	int len;
	int rwr;

	if (!filename)
	return (-1);

	file_d = open(filename, O_WRONLY | O_APPEND);

	if (file_d == -1)
	return (-1);

	if (text_content)
	{
	for (len = 0; text_content[len]; len++)
		;
	rwr = write(file_d, text_content, len);

	if (rwr == -1)
	return (-1);
	}

	close(file_d);
	return (1);
}

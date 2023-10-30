#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- reads a text file and prints to standard output
 * @filename: file to be read
 * @letters: number of letters it should read and print
 *
 * Return: the actual number of letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_d;
	char *buffer;
	ssize_t nrd, nwr;

	if (!filename)
	return (0);

	file_d = open(filename, O_RDONLY);

	if (file_d == -1)
	return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	return (0);

	nrd = read(file_d, buffer, letters);
	nwr = write(STDOUT_FILENO, buffer, nrd);

	close(file_d);
	free(buffer);

	return (nwr);
}

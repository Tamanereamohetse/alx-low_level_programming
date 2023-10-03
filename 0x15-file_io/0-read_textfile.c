#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the text file to be read
 * @letters: letters it should read and print
 *
 * Return: number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_d;
	ssize_t a;
	ssize_t b;

	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
	return (0);
	buffer = malloc(sizeof(char) * letters);
	b = read(file_d, buffer, letters);
	a = write(STDOUT_FILENO, buffer, b);
	free(buffer);
	close(file_d);
	return (a);
}

#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text and prints it to STDOUT
 * @filename: name of the file to be read
 * @letter: number of letters to read and print
 * Return: the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_d;
	ssize_t w;
	ssize_t t;
	char *buffer;

	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
	return (0);
	buffer = malloc(sizeof(char) * letters);
	t = read(file_d, buffer, letters);
	w = write(STDOUT_FILENO, buffer, t);

	free(buffer);
	close(file_d);
	return (w);
}

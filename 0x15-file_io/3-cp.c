#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - copies the content of a file to another file
 * @file: the name of the file
 *
 * Return: A pointer to the allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
	dprintf(STDERR_FILENO, "Error: Cant write to %s\n", file);
	exit(99);
	}
	
	return (buffer);
	}
/**
 * close_file - closes the description of the file
 * @fd: the value of the file descriptor
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
	dprintf(STDERR_FILENO, Error: Can't close fd FD_VALUE %d\n", fd;
	exit(100);
	}
}

/** main - copies from one file to another
 * @argc: number of arguments
 * @argv: pointers to the argument
 *
 * Return: 0 on success
 * Description: if the number of argument is incorrect - exit code 97
 * If file_from does not exist, or if you can not read it, exit with code 98
 * If file_to already exists, truncate it
 * If file_to or file_from cant be closed - exit code 100
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREATE | O_WRONLY | O_TRUNC, 0664);

	do
	{
	if (from == -1 || r == -1)
	{
	dprintf(STDERR_FILENO, "Error: cant read from file %s\n", argv[1];
	free(buffer);
	exit(98);
	}

	w = write(to, buffer, r);
	if (to == -1 || w == -1)
	{
	dprintf(STDERR_FILENO, "Error: Cant write to %s\n", argv[2];
	free(buffer);
	exit(99);
	}

	r = read(from, buffer, 1024);
	to = open(argv[2], O_WRONLY | O_APPEND);
	}
	while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

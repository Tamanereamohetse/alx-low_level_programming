#include <stdio.h>
#include "main.h"

/**
 * create_buffer- copies the content of a file to another file
 * @file: the name of the file
 *
 * Return: a pointer
 */
char *create_buffer(char *file)
{
	char buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
	dprintf(STDERR_FILENO, "ERROR: Cant write to %s\n", file);
	exit(99);
	}
	return (buff);
}

/**
 * close_file- closes the description of the file
 * @fd: file descriptor
 */
void close_file(int fd)
{
	int a;

	a = close(fd);
	if (c == -1)
	{
	dprintf(STDERR_FILENO, "Error: cant close fd %d\n", fd);
	exit(100);
	}
}

/**
 * main- copies the content of a file to another file
 * @argv: an array of pointers
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int to; read, write;
	char *buff;

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "Usage: cp file_from_file_to\n");
	exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	read = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | WRONLY | O_TRUNC, 0664);
	{
	if (from == -1 || r == -1)
	{
	dprintf(STDERR_FILENO, "Error: cant read from file %s\n", argv[1]);
	free(buff);
	exit(98);
	}

	write = write (to, buff, read);
	if (to == -1 || write == -1)
	{
	dprintf(STDERR_FILENO, "Error: cant write to %s\n" argv[2]);
	free(buff);
	exit(99);
	}

	read = read(from, buff, 1024);
	to = open(argv[2], O_WRONLY | O_APPEND);
	}
	while (r > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}


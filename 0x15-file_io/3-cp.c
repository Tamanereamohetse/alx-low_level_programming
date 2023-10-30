#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer- makes a buffer
 * @file: the name of the file
 *
 * Return: a pointer
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
	}
	return (buff);
}

/**
 * close_file- close a file descriptor
 * @fd: file descriptor
 */
void close_file(int fd)
{
	int a;

	a = close(fd);
	if (a == -1)
	{
	dprintf(STDERR_FILENO, "Can't close fd %d\n", fd);
	exit(100);
	}
}

/**
 * main- copies the content of a file to another file
 * @argc: an array of a pointer
 * @argv: pointer to the argument
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int from, to, rd, wr;
	char *buff;

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "USAGE: cp file_from_file_to\n");
	exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	rd = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
	if (from == -1 || rd == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	free(buff);
	exit(99);
	}

	rd = read(from, buff, 1024);
	to = open(argv[2], O_WRONLY | O_APPEND);
	} while (wr > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}



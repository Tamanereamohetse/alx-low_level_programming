#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void check_OI_stat(int stat, char *filename, char mode);
/**
 * main - copies a file to the other file
 * @argc: the number of arguments
 * @argv: pssed arguments
 *
 * Return: 1 on success, -1 on failure
 */
int main(int argc, char *argv[])
{
	int src, dest, n_read = 1024, wrote, close_src, close_dest;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
	exit(97);
	}
	src = open(argv[1], O_RDONLY);
	check_OI_stat(src, -1, argv[1], 'O');
	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_OI_stat(dest, -1, argv[2], 'W');
	while (n_read == 1024)
	{
	n_read = read(src, buffer, sizeof(buffer));
	if (n_read == -1)
	check_OI_stat(-1, -1, argv[1], 'O');
	wrote = write(dest, buffer, n_read);
	if (wrote == -1)
	check_OI_stat(-1, -1, argv[2], 'W');
	}
	close_src = close(src);
	check_OI_stat(close_src, src, NULL, 'C');
	close_dest = close(dest);
	check_OI_stat(close_dest, dest, NULL, 'C');
	return (0);
}

/**
 * check_IO_stat - runs a check if the the file is open or closed
 * @stat: file to be opened
 * @filename: the name of the file
 * @mode: close or open
 * fd: description of the file
 *
 * Return: void
 */
void check_IO_stat(int stat, int fd, char *filename, char mode)
{
	if (mode == 'C' && stat == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
	}
	else if (mode == 'O' && stat == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
	}
	else if (mode == 'W' && stat == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}

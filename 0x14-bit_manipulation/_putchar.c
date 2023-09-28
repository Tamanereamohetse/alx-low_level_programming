#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes c to stdout
 * @c: Character to print
 *
 * Return: 1 (Success)
 * On error, -1 is returned
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}

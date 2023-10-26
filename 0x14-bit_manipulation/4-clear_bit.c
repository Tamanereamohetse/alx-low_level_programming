#include <stdio.h>
#include "main.h"

/**
 * clear_bit- sets the value of a bit to 0 at a given index
 * @index: bit you want to set
 * @n: number to set
 *
 * Return: 1 if it worked
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int x;

	x = 1;
	x = x << index;
	if (index > sizeof(unsigned long int) * 8 || n == NULL)
	return (-1);
	if (((*n >> index) & 1) == 1)
	*n = x ^ *n;

	return (1);
}

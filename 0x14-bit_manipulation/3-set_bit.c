#include <stdio.h>
#include "main.h"

/**
 * set_bit- sets the value of a bit to 1 at a given index
 * @index: bit you want to set
 * @n: number to set
 *
 * Return: 1 if it worked
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int a;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	return (-1);
	a = 1 << index;
	*n = *n | a;
	return (1);
}

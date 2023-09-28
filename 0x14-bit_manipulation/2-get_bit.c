#include <stdio.h>
#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @index: the index, starting from 0
 * @n: number to check the value
 *
 * Return: the value of the bit at index index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int a;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	return (-1);
	for (a = 0; a < index; a++)
	n = n >> 1;
	return ((n & 1));
}

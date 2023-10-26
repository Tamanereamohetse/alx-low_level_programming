#include <stdio.h>
#include "main.h"

/**
 * get_bit- returns the value of a bit at a given index
 * @index: the index, starting from 0
 * @n: number to check value
 *
 * Return: the value of the bit at index index
 * or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int x;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	return (-1);
	for (x = 0; x < index; x++)
	n = n >> 1;
	return ((n & 1));
}

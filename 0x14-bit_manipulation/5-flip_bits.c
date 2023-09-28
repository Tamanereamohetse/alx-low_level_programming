#include <stdio.h>
#include "main.h"

/**
 * flip_bits - returns the number of bits
 * @n: first integer
 * @m: second integer
 *
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, count = 0;
	unsigned long int current;
	unsigned long int exc = n ^ m;

	for (x = 63; x >= 0; x--)
	{
	current = exc >> x;
	if (current & 1)
	count++;
	}
	return (count);
}

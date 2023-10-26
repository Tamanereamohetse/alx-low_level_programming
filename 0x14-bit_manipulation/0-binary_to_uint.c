#include "main.h"

/**
 * binary_to_uint- converts a binary number to an unsigned int
 * @b: pointing to a string
 *
 * Return: the converted number, or 0 if
 * here is one or more chars in the string
 */
unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int num;

	num = 0;
	if (!b)
	return (0);
	for (x = 0; b[x] != '\0'; x++)
	{
	if (b[x] != '0' && b[x] != '1')
	return (0);
	}
	for (x = 0; b[x] != '\0'; x++)
	{
	num <<= 1;
	if (b[x] == '1')
	num += 1;
	}
	return (num);
}


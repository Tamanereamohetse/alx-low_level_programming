#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: the string that contains the binary number
 *
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int dec_val = 0;

	if (!b)
	return (0);

	for (j = 0; b[j]; j++)
	{
	if (b[j] < '0' || b[j] > '1')
	return (0);
	dec_val = 2 * dec_val + (b[j] - '0');
	}

	return (dec_val);
}

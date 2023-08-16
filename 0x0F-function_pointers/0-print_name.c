#include "function_pointers.h"
#include <stdio.h>

/**
 * prints_name - prints name of a person
 * @name: name of a person
 * @f: pointers to function
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}

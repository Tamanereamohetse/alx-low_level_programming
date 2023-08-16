#include "function_pointers.h"
#include <stdio.h>

/**
 * prints_name - prints name of a person
 * @name: name of a person
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

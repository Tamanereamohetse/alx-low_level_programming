#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the end of a list_t list
 * @str: to be duplicated
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[le])
	len++;
	new = malloc(sizeof(list_t));
	
	if (*head == NULL)
	{
	*head = new;
	return (new);
	}

	while (temp->next)
	temp = temp->next;
	temp ->next = new;

	return (new);
}


#include "lists.h"

/**
 * sum_listint - calculates the sum of all data in a linked list
 * @head: first node in a linked list
 *
 * Returns: result of sum if the list is empty, return 0
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}

#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: double pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *temp = NULL;

	while (h != NULL && *h != NULL)
	{
		temp = (*h)->next;
		free(*h);
		*h = NULL;

		if (temp >= *h)
			break;

		*h = temp;
		len++;
	}

	return (len);
}

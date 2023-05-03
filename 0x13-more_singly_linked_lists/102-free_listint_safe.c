#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	listint_t *curr = *h, *temp;

	while (curr != NULL)
	{
		if (curr <= curr->next)
		{
			temp = curr->next;
			free(curr);
			curr = temp;
			len++;
		}
		else
		{
			free(curr);
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}

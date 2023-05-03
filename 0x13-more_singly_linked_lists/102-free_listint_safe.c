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
	listint_t *current, *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		current = *h;
		*h = (*h)->next;
		len++;
		if (current < *h)
		{
			free(current);
		}
		else
		{
			temp = *h;
			while (temp && current > temp)
			{
				temp = temp->next;
			}
			free(current);
			*h = temp;
		}
	}

	return (len);
}

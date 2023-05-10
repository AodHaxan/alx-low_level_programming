#include "lists.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t count = 0;

	if (head == NULL)
		exit(98);

	tortoise = head;
	hare = head;

	while (tortoise != NULL && hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				count++;
				printf("[%p] %d\n", (void *)tortoise, tortoise->n);
				tortoise = tortoise->next;
				hare = hare->next;
			}
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
			return (count + 1);
		}
		else
		{
			count++;
			printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		}
	}

	return (count);
}

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list, even if it has a loop.
 * @head: A pointer to the head node of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow, *fast;

	if (head == NULL)
		exit(98);

	slow = head;
	fast = head->next;

	while (fast != NULL && fast < fast->next)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		count++;
		slow = slow->next;
		fast = fast->next->next;
	}

	printf("[%p] %d\n", (void *)slow, slow->n);
	count++;

	if (fast != NULL)
	{
		printf("-> [%p] %d\n", (void *)fast, fast->n);
		count++;
	}

	return (count);
}


#include "lists.h"
/**
 * reverse_listint - Reverses a linked list
 * @head: Pointer to pointer to first node of linked list
 *
 * Return: Pointer to first node of reversed linked list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}


#include "lists.h"

/**
 * free_listint - Frees a linked list
 * @head: Pointer to the beginning of the linked list
 *
 * Return: void
 */

void free_listint(listint_t *head)
{
listint_t *temp;

while (head)
{
temp = head;
head = head->next;
free(temp);
}
}


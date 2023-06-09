#include "lists.h"
/**
 * pop_listint - Deletes the head node of a listint_t linked list, and returns
 *               the head node’s data (n).
 *
 * @head: Pointer to pointer to the head node of the linked list.
 *
 * Return: The data of the head node, or 0 if the linked list is empty.
 */
int pop_listint(listint_t **head)
{
listint_t *temp;
int n;

if (*head == NULL)
return (0);

temp = *head;
*head = temp->next;
n = temp->n;
free(temp);

return (n);
}


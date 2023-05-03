#include "lists.h"
/**
 * delete_nodeint_at_index - deletes the node at in listint_t linked list
 * @head: pointer to a pointer to the head of the list
 * @index: index of the node to be deleted (starting from 0)
 * Return: 1 if successful, -1 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
unsigned int i;
listint_t *temp, *prev;

if (head == NULL || *head == NULL)
return (-1);

if (index == 0)
{
temp = *head;
*head = (*head)->next;
free(temp);
return (1);
}

prev = *head;
for (i = 0; i < index - 1 && prev->next != NULL; i++)
prev = prev->next;

if (i < index - 1 || prev->next == NULL)
return (-1);

temp = prev->next;
prev->next = temp->next;
free(temp);

return (1);
}


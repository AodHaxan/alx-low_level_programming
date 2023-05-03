#include "lists.h"
/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a
 *                            linked list
 *
 * @head: A pointer to a pointer to the head of the linked list
 * @idx: The index of the list where the new node should be added
 * @n: The integer data to be stored in the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *temp = *head;
unsigned int i;

/* Check if the head pointer is NULL */
if (head == NULL)
return (NULL);

/* Create the new node and store the data */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;

/* Insert at the head */
if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}

/* Traverse to the index of the list */
for (i = 0; i < idx - 1; i++)
{
/* Check if the index is out of range */
if (temp == NULL || temp->next == NULL)
{
free(new_node);
return (NULL);
}
temp = temp->next;
}

/* Insert the new node */
new_node->next = temp->next;
temp->next = new_node;

return (new_node);
}


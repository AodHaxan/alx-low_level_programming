#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
    if (head == NULL || head->next == NULL)
        return (0);

    const listint_t *tortoise = head->next;
    const listint_t *hare = head->next->next;
    while (hare != NULL && hare->next != NULL)
    {
        if (tortoise == hare)
        {
            size_t count = 1;
            hare = hare->next;
            while (tortoise != hare)
            {
                count++;
                hare = hare->next;
            }
            return (count);
        }
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    size_t loop_len = looped_listint_len(head);
    if (loop_len == 0)
    {
        while (head != NULL)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
            count++;
        }
    }
    else
    {
        const listint_t *loop_start = head;
        for (size_t i = 0; i < loop_len; i++)
            loop_start = loop_start->next;

        const listint_t *node = head;
        while (node != loop_start)
        {
            printf("[%p] %d\n", (void *)node, node->n);
            node = node->next;
            count++;
        }
        printf("[%p] %d\n", (void *)node, node->n);
        node = node->next;
        count++;

        while (node != loop_start)
        {
            printf("[%p] %d\n", (void *)node, node->n);
            node = node->next;
            count++;
        }
        printf("-> [%p] %d\n", (void *)node, node->n);
        count++;
    }
    return (count);
}

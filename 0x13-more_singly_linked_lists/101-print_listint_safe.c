#include "lists.h"
#include <stdio.h>
size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);
/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;
	size_t count = 0, loop_size = 0;

	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			do {
				loop_size++;
				hare = hare->next;
			} while (tortoise != hare);
			tortoise = head;
			hare = head;
			for (count = 0; count < loop_size; count++)
				hare = hare->next;
			while (tortoise != hare)
			{
				count++;
				tortoise = tortoise->next;
				hare = hare->next;
			}
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
			while (count--)
			{
				printf("[%p] %d\n", (void *)head, head->n);
				head = head->next;
			}
			printf("-> [%p] %d\n", (void *)head, head->n);
			return (loop_size + count + 1);
		}
	}
	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		head = head->next;
	}
	return (count);
}


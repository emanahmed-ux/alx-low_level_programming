#include "lists.h"

/**
 * print_listint -  prints all the elements of a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint(const listint_t *h)
{
	const listint_t *ptr = h;
	size_t num = 0;

	printf("The list contains: ");
	for (; ptr != NULL; ptr = ptr->next)
	{
		printf("%d", ptr->n);
		num++;
		if (ptr->next != NULL)
			printf(", ");
	}
	printf("\n");

	return (num);
}

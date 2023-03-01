#include "main.h"

/**
 * reverse_array - function to reverse the contents of an array
 * @a: array to be reversed
 * @n: lenght of arrow a
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i = 0, t;
n = n - 1;
while (i < n)
{
	t = *(a + i);
	*(a + i) = *(a + n);
	*(a + n) = t;
	i++;
	n--;
}
}

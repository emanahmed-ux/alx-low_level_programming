#include "main.h"

/**
 * set_bit - sets a bit as 1
 * @n: pointer change the number
 * @index: bit to set to 1
 *
 * Return: 1 for success, -1 for failure
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n |= (1ul << index);
	return (1);
}

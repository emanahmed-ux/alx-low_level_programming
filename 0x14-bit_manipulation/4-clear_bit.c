#include "main.h"

/**
 * clear_bit - sets the value  given bit to 0
 * @n: pointer change the number
 * @index: clear
 *
 * Return: 1 for success, -1 for failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	*n &= ~(1UL << index);

	return (1);
}

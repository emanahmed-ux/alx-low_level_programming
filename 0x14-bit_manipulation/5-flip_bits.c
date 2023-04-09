#include "main.h"
#include <stdio.h>

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */


unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int exclusive = n ^ m;
	int count = 0;

	while (exclusive)
	{
		if (exclusive & 1)
			count++;
		exclusive >>= 1;
	}
	return (count);
}

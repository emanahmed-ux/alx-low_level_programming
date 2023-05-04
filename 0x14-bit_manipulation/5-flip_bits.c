#include "main.h"
#include <stdio.h>

/**
 * flip_bits - counts numbers change from one number to another
 * @n: first num
 * @m: second num
 *
 * Return: bits
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


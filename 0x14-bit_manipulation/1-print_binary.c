#include<stdio.h>
#include"main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int count = 0;

	/* Find the highest bit that is set */
	while ((mask << 1) <= n)
		mask <<= 1;

	/* Loop through each bit starting from the highest to the lowest */
	while (mask > 0)
	{
		if (n & mask)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');

		mask >>= 1;
	}

	/* If the number was 0, print 0 */
	if (!count)
		_putchar('0');
}

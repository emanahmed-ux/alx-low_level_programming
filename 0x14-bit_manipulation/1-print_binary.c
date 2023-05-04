#include<stdio.h>
#include"main.h"

/**
 * print_binary - prints equivalent of a decimal
 * @n: binary number
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int count = 0;

	while ((mask << 1) <= n)
		mask <<= 1;

	while (mask > 0)
	{
		if (n & mask)
		{
			_putchar('1');
			count++;
		}
		else if (count || mask == 1)
			_putchar('0');

		mask >>= 1;
	}

	if (!count)
		_putchar('0');
}


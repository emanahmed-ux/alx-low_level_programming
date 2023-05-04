#include<stdio.h>
#include"main.h"

/**
 * print_binary - prints equivalent of a decimal
 * @n: binary number
 */

void print_binary(unsigned long int n)
{
	unsigned long int i = 1;
	int mo = 0;

	while (i <= n)
	{
		i <<= 1;
	}

	while (i > 1)
	{
		i >>= 1;

		if (n & i)
		{
			_putchar('1');
			mo = 1;
		}
		else if (mo)
			_putchar('0');
		}

	if (!mo)
		_putchar('0');
}


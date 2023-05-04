#include<stdio.h>
#include"main.h"

/**
 * print_binary - prints equivalent of a decimal
 *
 * @n: binary number
 *
 * Return: a binary number
 */

void print_binary(unsigned long int n)
{
	int i;
	int found_first_one = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = (sizeof(unsigned long int) * 8) - 1; i >= 0; i--)
	{
		if (n >> i & 1)
		{
			_putchar('1');
			found_first_one = 1;
		}
		else if (found_first_one)
		{
			_putchar('0');
		}
	}
}

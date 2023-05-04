#include<stdio.h>
#include"main.h"


/**
 * get_bit - returns the value of a bit
 * @n: number search the bit in
 * @index: the index of return
 *
 * Return: the value index, or -1 if an error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);

	return ((n >> index) & 1);
}

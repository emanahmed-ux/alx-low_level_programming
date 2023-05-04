#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_to_uint - converts a binary to int
 * @b: string of  binary number
 *
 * Return: result
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		result <<= 1;

		if (b[i] == '1')
			result += 1;
	}
	return (result);
}


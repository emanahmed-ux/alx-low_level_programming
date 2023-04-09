#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	if (b == NULL)
	{
		return (0);
	}

	unsigned int result = 0;

	while (*b != '\0)

	{
		if (*b == '0')
		{
			result <<= 1;

		}
		else if (*b == '1')
		{
			result = (result << 1) | 1;

		}
		else
		{
			return (0);
		}
		b++;
	}

	return (result);
}

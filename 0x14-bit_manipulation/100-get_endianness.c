#include <stdio.h>
#include"main.h"

/**
 * get_endianness - checks if is there little or big endian
 * Return: 0 for big, 1 for smoll
 */

int get_endianness(void)
{
	int k = 1;
	char *ian = (char *)&k;

	if (*ian == 1)
		return (1);

	else
		return (0);
}

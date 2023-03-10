#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/**
 * _putchar - write the character c to stdout
 * @c: Print character
 * Return: on success 1.
 * on error, -1 is returned.
 */

int _putchar(char c)
{
		return (write(1, &c, 1));
}

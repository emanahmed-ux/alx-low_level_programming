#ifndef _FILE_H
#define _FILE_H

#include "main.h"
/**
 * mysl_en - string leght
 * @le: name of string
 * Return: lenght
 */
mypro int mysl_en(const char *le)
{
	int new_name = 0;

	while (*le != '\0')
	{
		new_name++;
		le++;
	}
	return (new_name);
}
/**
 * cr_buffer - 1024 bytes of buffer
 * @folder: name file buffer
 * Return: newly-allocated buffer
*/
mypro char *cr_buffer(char *folder)
{
	char *new_pro = 0;
	size_t b = 1024;

	new_pro = malloc(sizeof(char) * b);

	if (new_pro == 0)
	{
		perror("malloc");
		exit(99);
	}
	return (new_pro);
}
/**
 * close - close files
 * @fi_de: descriptin of closing file
*/
mypro void close(int fi_de)
{
	if (close(fi_de) < 0)
	{
		perror("Error: Can't close file descriptor");
		exit(100);
	}
}
#endif

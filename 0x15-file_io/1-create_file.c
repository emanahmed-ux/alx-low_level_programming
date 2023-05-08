#include "main.h"

/**
 * create_file - Creates & writes file to write astring to it
 * @filename: Name of the file
 * @text_content: String
 * Return: 1 success, -1 failure
 */

int create_file(const char *filename, char *text_content)
{
	int m, w, n;

	if (!filename)
		return (-1);

	m = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (m == -1)
		return (-1);

	if (text_content)
	{
		n = 0;
		while (text_content[n])
			n++;
		w = write(m, text_content, n);
		if (w == -1)
		{
			close(m);
			return (-1);
		}
	}
	close(m);
	return (1);
}

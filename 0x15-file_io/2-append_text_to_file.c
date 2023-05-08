#include "main.h"

/**
 * append_text_to_file - Appends textat the end.
 * @filename: A pointer.
 * @text_content: A string.
 *
 * Return: If the function fails or filename is NULL - -1.
 * If the file does not exist the user lacks write permissions - -1.
 * Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int m, r, k;

	if (!filename)
		return (-1);


	m = open(filename, O_WRONLY | O_APPEND);
	if (m == -1)
		return (-1);


	if (text_content)
	{
		k = 0;
		while (text_content[k])
			k++;
		r = write(m, text_content, k);
		if (r == -1)
		{
			close(m);
			return (-1);
		}
	}

	close(m);
	return (1);
}

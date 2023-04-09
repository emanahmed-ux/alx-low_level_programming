#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to stdout
 * @filename: Name of the file to be read
 * @letters: Number of letters to read and print
 *
 * Return: Number of bytes actually read and printed, or 0 if failed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t read_chars, written_chars;

	if (!filename || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (!buffer)
	{
		close(fd);
		return (0);
	}

	read_chars = read(fd, buffer, letters);
	if (read_chars < 0)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	buffer[read_chars] = '\0';
	written_chars = write(STDOUT_FILENO, buffer, read_chars);
	if (written_chars != read_chars)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	free(buffer);
	close(fd);
	return (written_chars);
}


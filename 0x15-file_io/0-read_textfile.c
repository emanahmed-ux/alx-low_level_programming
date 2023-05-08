#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - Read & prints stdout
 * @filename: file to be read
 * @letters: number of letters
 *
 * Return: Number of bytes printed, or 0 if failed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t b_read, b_written;
	char *buf_fer;

	if (filename == NULL || letters == 0)
		return (0);
	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf_fer = malloc(sizeof(char) * (letters + 1));
	if (buf_fer == NULL)
	{
		close(fd);
		return (0);
	}
	b_read = read(fd, buf_fer, letters);

	if (b_read == -1)
	{
		free(buf_fer);
		close(fd);
		return (0);
	}
	buf_fer[b_read] = '\0';
	b_written = write(STDOUT_FILENO, buf_fer, b_read);

	if (b_written == -1 || b_written != b_read)
	{
		free(buf_fer);
		close(fd);
		return (0);
	}
	free(buf_fer);
	close(fd);
	return (b_written);
}

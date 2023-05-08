#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buf(char *my_file);
void close_fi(int my_fld);

/**
 * create_buf - Allocates 1024 bytes.
 * @my_file: file buffer is storing chars for.
 *
 * Return: A pointer to the newly.
 */
char *create_buf(char *my_file)
{
	char *fer;

	fer = malloc(sizeof(char) * 1024);

	if (!fer)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", my_file);
		exit(99);
	}

	return (fer);
}
/**
 * main - Copies from a file to another.
 * @my_argv: argument vector.
 * @my_argc: argument count.
 *
 * Return: 0 on success.
 */
int main(int my_argc, char *my_argv[])
{
	int fm, to, s, h;
	char *bur;

	if (my_argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bur = create_buf(my_argv[2]);
	fm = open(my_argv[1], O_RDONLY);
	to = open(my_argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (fm == -1 || s == -1)
		{
			dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", my_argv[1]);
		free(bur);
		exit(98);
	}

	s = read(fm, bur, 1024);
	}

	while (s > 0)
	{
		h = write(to, bur, s);

		if (h == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", my_argv[2]);
			free(bur);
			exit(99);
		}

		s = read(fm, bur, 1024);
	}

	free(bur);
	close_fi(fm);
	close_fi(to);

	return (0);
}
/**
 * close_fi - Closes file.
 * @fld: file descriptor to be closed.
 */
void close_fi(int fld)
{
	int k;

	k = close(fld);

	if (k == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fld);
		exit(100);
	}
}

#include "main.h"

/**
 * cr_buffer - 1024 bytes of buffer
 * @folder: name file buffer
 * Return: newly-allocated buffer
*/
mypro char *cr_buffer(void)
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
 * main - Copies the contents of a file to another file.
 * @my_argc: number of arguments.
 * @my_argv: An array of pointers.
 * Return: 0 on success.
 * Description: incorrect - exit code 97, not found or read - exit code 98.
 *              cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int my_argc, char *my_argv[])
{
	int from_fil, to_fil, m, s;
	char buffer[BUFFER_SIZE];

	if (my_argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from_fil = open(my_argv[1], O_RDONLY);

	if (from_fil == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", my_argv[1]);
		exit(98);
	}
	to_fil = open(my_argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (to_fil == -1)
	{
		fprintf(stderr, "Error: Can't write to %s\n", my_argv[2]);
		close(from_fil);
		exit(99);
	}
	while ((m = read(from_fil, buffer, BUFFER_SIZE)) > 0)
	{
		s = write(to_fil, buffer, m);

		if (s == -1 || s != m)
		{
			fprintf(stderr, "Error: Can't write to %s\n", my_argv[2]);
			close(from_fil);
			close(to_fil);
			exit(99);
		}
	}
	if (m == -1)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", my_argv[1]);
		close(from_fil);
		close(to_fil);
		exit(98);
	}
	if (close(from_fil) == -1)
	{
		fprintf(stderr, "Error: Can't close file descriptor %d\n", from_fil);
		exit(100);
	}
	if (close(to_fil) == -1)
	{
		fprintf(stderr, "Error: Can't close file descriptor %d\n", to_fil);
		exit(100);
	}
	return (0);
}
/**
 * clo_se - close files
 * @fi_de: descriptin of closing file
*/
mypro void clo_se(int fi_de)
{
	if (close(fi_de) < 0)
	{
		perror("Error: Can't close file descriptor");
		exit(100);
	}
}

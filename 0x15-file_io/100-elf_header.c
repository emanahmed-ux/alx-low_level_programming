#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	if ((e_ident[0] ^ 0x7F) ||
			(e_ident[1] ^ 'E') ||
			(e_ident[2] ^ 'L') ||
			(e_ident[3] ^ 'F'))
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}
/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */

void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}
/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	if (e_ident[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else if (e_ident[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else
		printf("<unknown: 0x%x>\n", e_ident[EI_DATA]);
}
/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}
/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_ARM_AEABI:
			printf("ARM EABI\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: 0x%x>\n", e_ident[EI_OSABI]);
			break;
	}
}
/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       ");

	if (e_ident[EI_OSABI] == ELFOSABI_NONE)
		printf("%d\n", e_ident[EI_ABIVERSION]);
	else
		printf("<unknown: %x>\n", e_ident[EI_ABIVERSION]);
}
/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	const char *type_str = NULL;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type = (e_type << 8) | (e_type >> 8);
	}

	switch (e_type)
	{
	case ET_NONE:
		type_str = "NONE (None)";
		break;
	case ET_REL:
		type_str = "REL (Relocatable file)";
		break;
	case ET_EXEC:
		type_str = "EXEC (Executable file)";
		break;
	case ET_DYN:
		type_str = "DYN (Shared object file)";
		break;
	case ET_CORE:
		type_str = "CORE (Core file)";
		break;
	default:
		type_str = "<unknown>";
	}

	printf("  Type:                              %s\n", type_str);
}
/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)e_entry);
	} else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		printf("%#lx\n", e_entry);
	} else
	{
		printf("<unknown class>\n");
	}
}
/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Return: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		perror("close");
		exit(98);
	}
}
/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr *header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		close(fd);
		return (EXIT_FAILURE);
	}

	if (read(fd, header, sizeof(Elf64_Ehdr)) < (ssize_t)sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		free(header);
		close(fd);
		return (EXIT_FAILURE);
	}

	check_elf(header->e_ident);

	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


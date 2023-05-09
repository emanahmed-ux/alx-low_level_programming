#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define ID 16
void ver_sion(unsigned char *e_ident);
void clo_sing(int file_elf);
int main(
int dtr, char *ker[]);
void class(unsigned char *e_ident);
int elf_che(unsigned char *e_ident);
void magic(unsigned char *e_ident);
void osabi(unsigned char *e_ident);
void abi(unsigned char *e_ident);
void type(unsigned int mytype, unsigned char *e_ident);
void entry(unsigned long int myenter, unsigned char *e_ident);
void data(unsigned char *e_ident);
int main(int argc, char **argv);
/**
 * ver_sion - shows the version of the elf
 * @e_ident: pointers of arrays
*/
void ver_sion(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");

}
/**
 * clo_sing - close the elf
 * @file_elf: descriptor of elf
*/
void clo_sing(int file_elf)
{
	int name = close(file_elf);

	if (name == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_elf);
		exit(98);
	}
}
/**
 * class - prints class
 * @e_ident: pointer of array
*/
void class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;

		case ELFCLASS32:
		printf("ELF32\n");
		break;

		case ELFCLASS64:
		printf("ELF64\n");
		break;

		default:

		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
 * magic - shows magic number
 * @e_ident: pointer of array
*/
void magic(unsigned char *e_ident)
{
	int my_pro;

	printf("  Magic:   ");

	for (my_pro = 0; my_pro < EI_NIDENT; my_pro++)
	{
		printf("%02x ", e_ident[my_pro]);
	}
	printf("\n");
}
/**
 * osabi - shows OS/ABI
 * @e_ident: pointer of array
 */
void osabi(unsigned char *e_ident)
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
 * abi - shows ABI number
 * @e_ident: pointer of array
*/
void abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       ");

	if (e_ident[EI_OSABI] == ELFOSABI_NONE)
		printf("%d\n", e_ident[EI_ABIVERSION]);
	else
		printf("<unknown: %x>\n", e_ident[EI_ABIVERSION]);
}
/**
 * type - prints type of an ELF header
 * @e_ident: pointer of array
 * @mytype: ELF type
*/
void type(unsigned int mytype, unsigned char *e_ident)
{
	const char *newtype = 0;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		mytype = (mytype << 8) | (mytype >> 8);
	}
	switch (mytype)
	{
	case ET_NONE:
		newtype = "NONE (None)";
		break;
	case ET_REL:
		newtype = "REL (Relocatable file)";
		break;
	case ET_EXEC:
		newtype = "EXEC (Executable file)";
		break;
	case ET_DYN:
		newtype = "DYN (Shared object file)";
		break;
	case ET_CORE:
		newtype = "CORE (Core file)";
		break;
	default:
		newtype = "<unknown>";
	}

	printf("  Type:                              %s\n", newtype);
}
/**
 * entry - entry point
 * @myenter: address of entry point
 * @e_ident: pointer of array
*/
void entry(unsigned long int myenter, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#lx\n", myenter);
		}
	else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		printf("%#lx\n", (unsigned long)myenter);
	} else
	{
		printf("<unknown class>\n");
	}
}
/**
 * data - Prints the data.
 * @e_ident: pointer to an array.
 */
void data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATANONE)
		printf("Invale_ident data encoding\n");
}
/**
 * elf_che - see files in ELF
 * @e_ident: pointer of array
 * Description: if elf file dosn't exsiest - exit code 98
 * Return: 0
*/
int elf_che(unsigned char *e_ident)
{
	if ((e_ident[0] ^ 0x7F) ||
			(e_ident[1] ^ 'E') ||
			(e_ident[2] ^ 'L') ||
			(e_ident[3] ^ 'F'))
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
	return (0);
}
/**
 * main - shows information in file ELF
 * @dtr: arguments supplied
 * @ker: pointers of array
 * Return: 0 on success
*/
int main(int dtr, char *ker[])
{
	Elf64_Ehdr *front;
	int fd, read_ret;

	if (dtr != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", ker[0]);
		exit(1);
	}
	fd = open(ker[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", ker[1]);
		exit(98);
	}
	front = malloc(sizeof(Elf64_Ehdr));
	if (front == 0)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(98);
	}
	read_ret = read(fd, front, sizeof(Elf64_Ehdr));
	if (read_ret < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", ker[1]);
		free(front);
		exit(98);
	}
	printf("ELF Header:\n");
	elf_che(front->e_ident);
	magic(front->e_ident);
	class(front->e_ident);
	data(front->e_ident);
	ver_sion(front->e_ident);
	osabi(front->e_ident);
	abi(front->e_ident);
	type(front->e_type, front->e_ident);
	free(front);
	close(fd);
	return (0);
}

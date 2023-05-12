#include "elf_a.h"
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
		printf(my_pro == EI_NIDENT - 1 ? "\n" : " ");
	}
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

	if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("%d\n", e_ident[EI_ABIVERSION]);
	else
		printf("<unknown: %x>\n", e_ident[EI_ABIVERSION]);
}
/**
 * type - prints type of an ELF header
 * @e_ident: pointer of array
 * @e_type: ELF type
*/
void type(unsigned int e_type, unsigned char *e_ident)
{
	const char *newtype = 0;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type = (e_type << 8) | (e_type >> 8);
	}
	switch (e_type)
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
 * @e_entry: address of entry point
 * @e_ident: pointer of array
*/
void entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		if (e_ident[EI_DATA] == ELFDATA2MSB)
		{
			e_entry = ((e_entry & 0xFF00000000000000UL) >> 56) |
				((e_entry & 0x00FF000000000000UL) >> 40) |
				((e_entry & 0x0000FF0000000000UL) >> 24) |
				((e_entry & 0x000000FF00000000UL) >> 8) |
				((e_entry & 0x00000000FF000000UL) << 8) |
				((e_entry & 0x0000000000FF0000UL) << 24) |
				((e_entry & 0x000000000000FF00UL) << 40) |
				((e_entry & 0x00000000000000FFUL) << 56);
			e_entry = e_entry & 0xFFFFFFFFFFFFFFFFUL;
		}
		printf("%#lx\n", e_entry);
	} else
	{
		if (e_ident[EI_DATA] == ELFDATA2MSB)
		{
			e_entry = ((e_entry & 0xFF000000) >> 24) |
				((e_entry & 0x00FF0000) >> 8) |
				((e_entry & 0x0000FF00) << 8) |
				((e_entry & 0x000000FF) << 24);
			e_entry = e_entry & 0xFFFFFFFFUL;
		}
		printf("%#x\n", (unsigned int) e_entry);
	}
}
/**
 * data - Prints the data.
 * @e_ident: pointer to an array.
 */
void data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	if (e_ident[EI_DATA] == ELFDATANONE)
	{
		printf("none\n");
	} else if (e_ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
	} else if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
	} else
	{
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}
/**
 * elf_che - see files in ELF
 * @e_ident: pointer of array
 * Return: 0 on success, 98 on failure
 */
int elf_che(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 ||
			e_ident[EI_MAG1] != ELFMAG1 ||
			e_ident[EI_MAG2] != ELFMAG2 ||
			e_ident[EI_MAG3] != ELFMAG3 ||
			e_ident[EI_CLASS] != ELFCLASS64 ||
			e_ident[EI_DATA] != ELFDATA2LSB ||
			e_ident[EI_VERSION] != EV_CURRENT)
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
	Elf64_Ehdr *header;
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
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == 0)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(98);
	}
	read_ret = read(fd, header, sizeof(Elf64_Ehdr));
	if (read_ret < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", ker[1]);
		free(header);
		exit(98);
	}
	printf("ELF Header:\n");
	elf_che(header->e_ident);
	magic(header->e_ident);
	class(header->e_ident);
	data(header->e_ident);
	ver_sion(header->e_ident);
	osabi(header->e_ident);
	abi(header->e_ident);
	type(header->e_type, header->e_ident);
	entry(header->e_entry, header->e_ident);
	free(header);
	close(fd);
	return (0);
}

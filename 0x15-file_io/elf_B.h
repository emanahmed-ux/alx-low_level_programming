#ifndef ELF_A_H
#define ELF_A_H

#include "main.h"

/**
 * osabi - shows OS/ABI 
 * @id: pointer of array 
 * 
 */
mypro void osabi(unsigned char *id)
{
	printf("  OS/ABI:                            ");

	switch (id[EI_OSABI])
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
			printf("<unknown: 0x%x>\n", id[EI_OSABI]);
			break;
	}

}
/**
 * abi - shows ABI number
 * @id: pointer of array
*/
mypro void abi(unsigned char *id)
{
    printf("  ABI Version:                       ");

	if (id[EI_OSABI] == ELFOSABI_NONE)
		printf("%d\n", id[EI_ABIVERSION]);
	else
		printf("<unknown: %x>\n", id[EI_ABIVERSION]);
}
/**
 * type - prints type of an ELF header 
 * @id: pointer of array
 * @mytype: ELF type
*/
mypro void type(unsigned int mytype, unsigned char *id)
{
   const char *newtype = 0;

	if (id[EI_DATA] == ELFDATA2MSB)
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

	printf("  Type:                              %s\n", type_str);
}
/**
 * entry - entry point
 * @myenter: address of entry point
 * @id: pointer of array
*/
mypro void entry(unsigned int myenter, unsigned char *id)
{
	printf("  Entry point address:               ");

	if (id[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)myenter);
		} else if (id[EI_CLASS] == ELFCLASS64)
	{
		printf("%#lx\n", myenter);
	} else
	{
		printf("<unknown class>\n");
	}
}
/**
 * data - Prints the data.
 * @id: pointer to an array.
 */
void data(unsigned char *id)
{
	printf("  Data:                              ");

	printf("%s\n", (id[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" :
			(id[EI_DATA] == ELFDATA2MSB) ? "2's complement, big endian" :
			(id[EI_DATA] == ELFDATANONE) ? "none" :
			"<unknown: %x>", id[EI_DATA]);
}

#endif
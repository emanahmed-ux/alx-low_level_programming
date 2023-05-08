#ifndef ELF_A_H
#define ELF_A_H

#include "main.h"

/**
 * elf_che - see files in ELF
 * @id: pointer of array 
 * 
 * Description: if elf file dosn't exsiest - exit code 98
*/
mypro void elf_che(unsigned char *id)
{
    if ((id[0] ^ 0x7F) ||
			(id[1] ^ 'E') ||
			(id[2] ^ 'L') ||
			(id[3] ^ 'F'))
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}

}
/**
 * magic - shows magic number
 * @id: pointer of array
*/
mypro void magic(unsigned char *id)
{
    printf("  Magic:   ");

	for (int my_pro = 0; my_pro < ID; my_pro++)
	{
		printf("%02x ", id[my_pro]);
	}
	printf("\n");
}
/**
 * class - prints class 
 * @id: pointer of array
*/
mypro void class(unsigned char *id)
{
    printf("  Class:                             ");

	if (id[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (id[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (id[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", id[EI_CLASS]);
}


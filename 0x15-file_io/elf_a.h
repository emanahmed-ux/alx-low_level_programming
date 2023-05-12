#ifndef MAIN_H
#define MAIN_H
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
int main(int dtr, char *ker[]);
void class(unsigned char *e_ident);
int elf_che(unsigned char *e_ident);
void magic(unsigned char *e_ident);
void osabi(unsigned char *e_ident);
void abi(unsigned char *e_ident);
void type(unsigned int e_type, unsigned char *e_ident);
void entry(unsigned long int e_entry, unsigned char *e_ident);
void data(unsigned char *e_ident);
int main(int argc, char **argv);
#endif

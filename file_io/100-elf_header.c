#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - print error message and exit
 * @msg: message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * main - display ELF header information
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t r;
	unsigned char ident[EI_NIDENT];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Can't open file");

	r = read(fd, ident, EI_NIDENT);
	if (r != EI_NIDENT)
	{
		close(fd);
		print_error("Can't read ELF ident");
	}

	if (ident[EI_MAG0] != ELFMAG0 || ident[EI_MAG1] != ELFMAG1 ||
	    ident[EI_MAG2] != ELFMAG2 || ident[EI_MAG3] != ELFMAG3)
	{
		close(fd);
		print_error("Not an ELF file");
	}

	printf("ELF Header:\n  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             ");
	if (ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("Invalid class\n");

	printf("  Data:                              ");
	if (ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Invalid data encoding\n");

	printf("  Version:                           %d (current)\n", ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		default: printf("<unknown: %x>\n", ident[EI_OSABI]); break;
	}

	printf("  ABI Version:                       %d\n", ident[EI_ABIVERSION]);

	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		print_error("Can't lseek");
	}

	if (ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr h32;

		r = read(fd, &h32, sizeof(h32));
		if (r != sizeof(h32))
		{
			close(fd);
			print_error("Can't read ELF32 header");
		}

		printf("  Type:                              ");
		switch (h32.e_type)
		{
			case ET_NONE: printf("NONE (None)\n"); break;
			case ET_REL: printf("REL (Relocatable file)\n"); break;
			case ET_EXEC: printf("EXEC (Executable file)\n"); break;
			case ET_DYN: printf("DYN (Shared object file)\n"); break;
			case ET_CORE: printf("CORE (Core file)\n"); break;
			default: printf("<unknown: %x>\n", h32.e_type); break;
		}

		printf("  Entry point address:               0x%x\n", h32.e_entry);
	}
	else if (ident[EI_CLASS] == ELFCLASS64)
	{
		Elf64_Ehdr h64;

		r = read(fd, &h64, sizeof(h64));
		if (r != sizeof(h64))
		{
			close(fd);
			print_error("Can't read ELF64 header");
		}

		printf("  Type:                              ");
		switch (h64.e_type)
		{
			case ET_NONE: printf("NONE (None)\n"); break;
			case ET_REL: printf("REL (Relocatable file)\n"); break;_

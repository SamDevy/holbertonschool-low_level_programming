#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - print an error message to stderr and exit with 98
 * @msg: error message
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * main - displays the information contained in the ELF header of a file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t bytes_read;
	unsigned char e_ident[EI_NIDENT];
	int i;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Can't open file");

	/* اقرأ أول 16 بايت لتتحقق من التوقيع */
	bytes_read = read(fd, e_ident, EI_NIDENT);
	if (bytes_read != EI_NIDENT)
	{
		close(fd);
		print_error("Can't read ELF ident");
	}

	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
		e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
	{
		close(fd);
		print_error("Not an ELF file");
	}

	/* ارجع لبداية الملف واقرأ الرأس كاملًا */
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		print_error("Can't lseek");
	}
	bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read != sizeof(header))
	{
		close(fd);
		print_error("Can't read ELF header");
	}

	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header.e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASS32: printf("ELF32\n"); break;
		case ELFCLASS64: printf("ELF64\n"); break;
		default: printf("Invalid class\n"); break;
	}

	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("Invalid data encoding\n");
			break;
	}

	printf("  Version:                           %d (current)\n",
		   header.e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		default: printf("<unknown: %x>\n", header.e_ident[EI_OSABI]); break;
	}

	printf("  ABI Version:                       %d\n",
		   header.e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header.e_type)
	{
		case ET_NONE: printf("NONE (None)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break_

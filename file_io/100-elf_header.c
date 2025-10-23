#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void err_exit(char *msg)
{
	perror(msg);
	exit(98);
}

void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i != EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

void print_class(unsigned char ei_class)
{
	printf("  Class:                             ");
	switch (ei_class)
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", ei_class);
	}
}

void print_data(unsigned char ei_data)
{
	printf("  Data:                              ");
	switch (ei_data)
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", ei_data);
	}
}

void print_version(unsigned char ei_version)
{
	printf("  Version:                           ");
	if (ei_version == EV_CURRENT)
		printf("%d (current)\n", ei_version);
	else
		printf("%d\n", ei_version);
}

void print_osabi(unsigned char ei_osabi)
{
	printf("  OS/ABI:                            ");
	switch (ei_osabi)
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
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
		default:
			printf("<unknown: %x>\n", ei_osabi);
	}
}

void print_abiversion(unsigned char abi_version)
{
	printf("  ABI Version:                       %d\n", abi_version);
}

void print_type(unsigned short e_type, int is_big_endian)
{
	if (is_big_endian)
		e_type = (e_type >> 8) | (e_type << 8);

	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

unsigned long read_entry(unsigned char *header, unsigned char ei_class,
			 int is_big_endian)
{
	unsigned long entry = 0;
	int i;

	if (ei_class == ELFCLASS32)
	{
		unsigned char *p = header + 24;

		if (is_big_endian)
		{
			for (i = 0; i < 4; i++)
				entry = (entry << 8) + p[i];
		}
		else
		{
			for (i = 3; i >= 0; i--)
				entry = (entry << 8) + p[i];
		}
	}
	else if (ei_class == ELFCLASS64)
	{
		unsigned char *p = header + 24;

		if (is_big_endian)
		{
			for (i = 0; i < 8; i++)
				entry = (entry << 8) + p[i];
		}
		else
		{
			for (i = 7; i >= 0; i--)
				entry = (entry << 8) + p[i];
		}
	}

	return (entry);
}

void read_elf_header(int fd, unsigned char *header, unsigned char ei_class)
{
	ssize_t n_read;

	if (lseek(fd, 0, SEEK_SET) == -1)
		err_exit("Error: Can't seek file");

	if (ei_class == ELFCLASS32)
	{
		n_read = read(fd, header, 52);
		if (n_read != 52)
		{
			dprintf(STDERR_FILENO, "Error: Can't read full ELF32 header\n");
			close(fd);
			exit(98);
		}
	}
	else if (ei_class == ELFCLASS64)
	{
		n_read = read(fd, header, 64);
		if (n_read != 64)
		{
			dprintf(STDERR_FILENO, "Error: Can't read full ELF64 header\n");
			close(fd);
			exit(98);
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Invalid ELF class\n");
		close(fd);
		exit(98);
	}
}

int main(int argc, char **argv)
{
	int fd;
	unsigned char e_ident[EI_NIDENT], header[64];
	unsigned char ei_class, ei_data, ei_version, ei_osabi, ei_abiversion;
	unsigned short e_type;
	int is_big_endian;
	unsigned long entry_point;
	ssize_t n_read;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_exit("Error: Can't read file");

	n_read = read(fd, e_ident, EI_NIDENT);
	if (n_read != EI_NIDENT)
	{
		dprintf(STDERR_FILENO, "Error: Can't read ELF header\n");
		close(fd);
		exit(98);
	}

	if (e_ident[0] != 0x7f || e_ident[1] != 'E' ||
		e_ident[2] != 'L' || e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}

	ei_class = e_ident[EI_CLASS];
	ei_data = e_ident[EI_DATA];
	ei_version = e_ident[EI_VERSION];
	ei_osabi = e_ident[EI_OSABI];
	ei_abiversion = e_ident[EI_ABIVERSION];

	read_elf_header(fd, header, ei_class);

	if (ei_data == ELFDATA2MSB)
		is_big_endian = 1;
	else if (ei_data == ELFDATA2LSB)
		is_big_endian = 0;
	else
	{
		dprintf(STDERR_FILENO, "Error: Unknown data encoding\n");
		close(fd);
		exit(98);
	}

	e_type = *(unsigned short *)(header + 16);

	printf("ELF Header:\n");
	print_magic(e_ident);
	print_class(ei_class);
	print_data(ei_data);
	print_version(ei_version);
	print_osabi(ei_osabi);
	print_abiversion(ei_abiversion);
	print_type(e_type, is_big_endian);

	entry_point = read_entry(header, ei_class, is_big_endian);
	printf("  Entry point address:               ");
	if (ei_class == ELFCLASS32)
		printf("0x%x\n", (unsigned int)entry_point);
	else
		printf("0x%lx\n", entry_point);

	close(fd);
	return (0);
}

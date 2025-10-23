#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

void print_error_and_exit(const char *msg)
{
    dprintf(STDERR_FILENO, "%s\n", msg);
    exit(98);
}

void print_magic(unsigned char *ident)
{
    int i;
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", ident[i]);
        if (i == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

void print_class(unsigned char class)
{
    printf("  Class:                             ");
    switch (class)
    {
        case ELFCLASSNONE: printf("None\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown: %x>\n", class); break;
    }
}

void print_data(unsigned char data)
{
    printf("  Data:                              ");
    switch (data)
    {
        case ELFDATANONE: printf("None\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown: %x>\n", data); break;
    }
}

void print_version(unsigned char version)
{
    printf("  Version:                           %d", version);
    if (version == EV_CURRENT)
        printf(" (current)\n");
    else
        printf("\n");
}

void print_osabi(unsigned char osabi)
{
    printf("  OS/ABI:                            ");
    switch (osabi)
    {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
        default: printf("<unknown: %x>\n", osabi); break;
    }
}

void print_abiversion(unsigned char abiver)
{
    printf("  ABI Version:                       %d\n", abiver);
}

void print_type(uint16_t e_type, unsigned char data)
{
    /* Convert e_type according to endianness */
    if (data == ELFDATA2MSB)
    {
        e_type = (e_type >> 8) | (e_type << 8);
    }

    printf("  Type:                              ");
    switch (e_type)
    {
        case ET_NONE: printf("NONE (None)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %x>\n", e_type); break;
    }
}

void print_entry(unsigned long long entry, unsigned char class)
{
    printf("  Entry point address:               ");
    if (class == ELFCLASS32)
        printf("0x%lx\n", (unsigned long)entry);
    else
        printf("0x%llx\n", entry);
}

int main(int argc, char *argv[])
{
    int fd;
    ssize_t n;
    unsigned char ident[EI_NIDENT];
    Elf32_Ehdr ehdr32;
    Elf64_Ehdr ehdr64;
    int i;

    if (argc != 2)
    {
        print_error_and_exit("Usage: elf_header elf_filename");
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error_and_exit("Error: Cannot open file");
    }

    /* Read ELF identification bytes */
    n = read(fd, ident, EI_NIDENT);
    if (n != EI_NIDENT)
    {
        close(fd);
        print_error_and_exit("Error: Cannot read ELF header");
    }

    /* Check ELF magic */
    if (ident[EI_MAG0] != ELFMAG0 ||
        ident[EI_MAG1] != ELFMAG1 ||
        ident[EI_MAG2] != ELFMAG2 ||
        ident[EI_MAG3] != ELFMAG3)
    {
        close(fd);
        print_error_and_exit("Error: Not an ELF file");
    }

    printf("ELF Header:\n");
    print_magic(ident);
    print_class(ident[EI_CLASS]);
    print_data(ident[EI_DATA]);
    print_version(ident[EI_VERSION]);
    print_osabi(ident[EI_OSABI]);
    print_abiversion(ident[EI_ABIVERSION]);

    /* Now read rest of ELF header depending on class */
    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        close(fd);
        print_error_and_exit("Error: lseek failed");
    }

    if (ident[EI_CLASS] == ELFCLASS32)
    {
        n = read(fd, &ehdr32, sizeof(Elf32_Ehdr));
        if (n != sizeof(Elf32_Ehdr))
        {
            close(fd);
            print_error_and_exit("Error: Cannot read ELF header");
        }
        print_type(ehdr32.e_type, ident[EI_DATA]);
        print_entry(ehdr32.e_entry, ELFCLASS32);
    }
    else if (ident[EI_CLASS] == ELFCLASS64)
    {
        n = read(fd, &ehdr64, sizeof(Elf64_Ehdr));
        if (n != sizeof(Elf64_Ehdr))
        {
            close(fd);
            print_error_and_exit("Error: Cannot read ELF header");
        }
        print_type(ehdr64.e_type, ident[EI_DATA]);
        print_entry(ehdr64.e_entry, ELFCLASS64);
    }
    else
    {
        close(fd);
        print_error_and_exit("Error: Invalid ELF Class");
    }

    close(fd);
    return 0;
}

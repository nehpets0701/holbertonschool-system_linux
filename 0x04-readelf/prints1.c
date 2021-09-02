#include "elfs.h"

/**
*printMagic-prints magic bytes
*@bytes:bytes
*/
void printMagic(unsigned char *bytes)
{
	size_t i;
	unsigned char *ident = ((Elf64_Ehdr *)bytes)->e_ident;

	printf("  Magic:   ");
	for (i = 0; i < 16; ++i)
	{
		printf("%02x ", ident[i]);
	}
	printf("\n");
}

/**
*printStrTable-prints string table
*@bytes:bytes
*@class:class
*@endianess:endianess
*/
void printStrTable(unsigned char *bytes, int class, int endianess)
{
	uint16_t shstrndx = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_shstrndx :
		((Elf64_Ehdr *) bytes)->e_shstrndx;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &shstrndx, 2);

	printf("  Section header string table index: %d\n", shstrndx);
}

/**
 * printClass - 32bit or 64bit
 * @bytes: character array
 */
void printClass(unsigned char *bytes)
{
	unsigned char class_name = ((Elf64_Ehdr *) bytes)->e_ident[EI_CLASS];

	printf("  Class:                             ");
	switch (class_name)
	{
	case (ELFCLASS32):
		puts("ELF32");
		break;
	case (ELFCLASS64):
		puts("ELF64");
		break;
	case ELFCLASSNONE:
	default:
		puts("Invalid Class");
		break;
	}
}

/**
 * printData - Print endianess
 * @bytes: character array
 */
void printData(unsigned char *bytes)
{
	unsigned char data = ((Elf64_Ehdr *) bytes)->e_ident[EI_DATA];

	printf("  Data:                              ");
	switch (data)
	{
	case (ELFDATA2LSB):
		puts("2's complement, little endian");
		break;
	case (ELFDATA2MSB):
		puts("2's complement, big endian");
		break;
	case (ELFDATANONE):
	default:
		puts("Unknown data format");
		break;
	}
}

/**
 * printVersion - Print version info
 * @bytes: character array
 */
void printVersion(unsigned char *bytes)
{
	unsigned char version = ((Elf64_Ehdr *) bytes)->e_ident[EI_VERSION];

	printf("  Version:                           %d", version);
	switch (version)
	{
	case (EV_CURRENT):
		puts(" (current)");
		break;
	case (EV_NONE):
	default:
		puts("");
		break;
	}
}

#include "elfs.h"

/**
 * printSectionHeaders - Print section headers
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printSectionHeaders(unsigned char *bytes, int class, int endianess)
{
	Elf64_Off *headers64;
	Elf32_Off *headers32;

	printf("  Start of section headers:          ");
	if (class == ELFCLASS32)
	{
		headers32 = &((Elf32_Ehdr *) bytes)->e_shoff;
		if (endianess == ELFDATA2MSB)
			reverse((unsigned char *) headers32, 4);
		printf("%u", *headers32);

	}
	else
	{
		headers64 = &((Elf64_Ehdr *) bytes)->e_shoff;
		if (endianess == ELFDATA2MSB)
			reverse((unsigned char *) headers64, 8);
		printf("%lu", *headers64);

	}
	puts(" (bytes into file)");
}

/**
 * printFlags - Print flags
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printFlags(unsigned char *bytes, int class, int endianess)
{
	uint32_t flags = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_flags :
		((Elf64_Ehdr *) bytes)->e_flags;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &flags, 4);
	printf("  Flags:                             0x%x\n", flags);
}

/**
 * printHeaderSize - Print header size
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printHeaderSize(unsigned char *bytes, int class, int endianess)
{
	uint16_t ehsize = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_ehsize :
		((Elf64_Ehdr *) bytes)->e_ehsize;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &ehsize, 2);
	printf("  Size of this header:               %d (bytes)\n", ehsize);
}

/**
 * printProgramHeaderSize - Print program_header_size
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printProgramHeaderSize(unsigned char *bytes, int class, int endianess)
{
	uint16_t phentsize = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_phentsize :
		((Elf64_Ehdr *) bytes)->e_phentsize;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &phentsize, 2);
	printf("  Size of program headers:           %d (bytes)\n", phentsize);
}

/**
 * printNumProgramHeaders - Print num_program_headers
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printNumProgramHeaders(unsigned char *bytes, int class, int endianess)
{
	uint16_t phnum = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_phnum :
		((Elf64_Ehdr *) bytes)->e_phnum;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &phnum, 2);
	printf("  Number of program headers:         %d\n", phnum);
}

#include "elfs.h"

/**
 * printSectionHsize - Print section size
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printSectionHsize(unsigned char *bytes, int class, int endianess)
{
	uint16_t shentsize = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_shentsize :
		((Elf64_Ehdr *) bytes)->e_shentsize;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &shentsize, 2);
	printf("  Size of section headers:           %d (bytes)\n", shentsize);
}

/**
 * printNumSectionHeaders - Print number of section headers
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printNumSectionHeaders(unsigned char *bytes, int class, int endianess)
{
	uint16_t shnum = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_shnum :
		((Elf64_Ehdr *) bytes)->e_shnum;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &shnum, 2);
	printf("  Number of section headers:         %d\n", shnum);
}

#include "elfs.h"

/**
 * get_section_off - Get section offset
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 * Return: section offset
 */
Elf64_Off get_section_off(unsigned char *bytes, int class, int endianess)
{
	Elf64_Off off = class == ELFCLASS32 ?
		((Elf32_Shdr *) bytes)->sh_offset :
		((Elf64_Shdr *) bytes)->sh_offset;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &off, class == ELFCLASS32 ? 4 : 8);
	return (off);
}

/**
 * get_section_size- Gets section size
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 * Return: section size
 */
uint64_t get_section_size(unsigned char *bytes, int class, int endianess)
{
	uint64_t size = class == ELFCLASS32 ?
		((Elf32_Shdr *) bytes)->sh_size :
		((Elf64_Shdr *) bytes)->sh_size;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &size, class == ELFCLASS32 ? 4 : 8);

	return (size);
}

/**
 * get_string_table_idx - Print Section header string table index
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 * Return: index of string table section
 */
uint16_t get_string_table_idx(unsigned char *bytes, int class, int endianess)
{
	uint16_t shstrndx = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_shstrndx :
		((Elf64_Ehdr *) bytes)->e_shstrndx;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &shstrndx, 2);

	return (shstrndx);
}

/**
 * get_num_section_headers - get number of section headers
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 * Return: number of section headers
 */
uint16_t get_num_section_headers(unsigned char *bytes, int class,
				 int endianess)
{
	uint16_t shnum = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_shnum :
		((Elf64_Ehdr *) bytes)->e_shnum;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &shnum, 2);
	return (shnum);
}

/**
 * get_section_hsize - get section size
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 * Return: section size
 */
uint16_t get_section_hsize(unsigned char *bytes, int class, int endianess)
{
	uint16_t shentsize = class == ELFCLASS32 ?
		((Elf32_Ehdr *) bytes)->e_shentsize :
		((Elf64_Ehdr *) bytes)->e_shentsize;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &shentsize, 2);
	return (shentsize);
}

#include "elfs.h"

/**
 * printSectionLk - print section link
 * @data: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printSectionLk(unsigned char *data, int class, int endianess)
{
	uint32_t link = class == ELFCLASS32 ?
		((Elf32_Shdr *) data)->sh_link :
		((Elf64_Shdr *) data)->sh_link;

	if (endianess == ELFDATA2MSB) /* TODO: be careful */
		reverse((unsigned char *) &link, class == ELFCLASS32 ? 4 : 4);
	printf(" %2u", link);
}

/**
 * printSectionInf - print section info
 * @data: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printSectionInf(unsigned char *data, int class, int endianess)
{
	uint32_t info = class == ELFCLASS32 ?
		((Elf32_Shdr *) data)->sh_info :
		((Elf64_Shdr *) data)->sh_info;

	if (endianess == ELFDATA2MSB) /* TODO: be careful */
		reverse((unsigned char *) &info, class == ELFCLASS32 ? 4 : 4);
	printf(" %3u", info);
}

/**
 * printSectionAl - print section address align
 * @data: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printSectionAl(unsigned char *data, int class, int endianess)
{
	uint64_t addralign = class == ELFCLASS32 ?
		((Elf32_Shdr *) data)->sh_addralign :
		((Elf64_Shdr *) data)->sh_addralign;

	if (endianess == ELFDATA2MSB) /* TODO: be careful */
		reverse((unsigned char *) &addralign, class == ELFCLASS32 ? 4 : 8);
	printf(" %2lu\n", addralign);
}

/**
 * printSectionHeaderNames - print header field
 * @class: ELFCLASS32 or ELFCLASS64
 */
void printSectionHeaderNames(int class)
{
	printf("Section Headers:\n");
	printf("  [Nr] Name              Type            ");
	if (class == ELFCLASS32)
		printf("Addr     Off    Size   ES Flg Lk Inf Al\n");
	else
		printf("Address          Off    Size   ES Flg Lk Inf Al\n");
}

/**
 * printKeyToFlags - print section flags explanation
 * @class: ELFCLASS32 or ELFCLASS64
 */
void printKeyToFlags(int class)
{
	printf("Key to Flags:\n");

	printf("  W (write), A (alloc), X (execute), M (merge), S (strings)");

	if (class == ELFCLASS64)
		printf(", l (large)");

	printf("\n  I (info), L (link order), G (group), T (TLS), %s\n",
	       "E (exclude), x (unknown)");

	printf("  O (extra OS processing required) o (OS specific),%s\n",
	       " p (processor specific)");
}

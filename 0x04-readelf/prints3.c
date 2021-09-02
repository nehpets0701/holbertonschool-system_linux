#include "elfs.h"

/**
 * printAbiVersion - Print abi version
 * @bytes: character array
 */
void printAbiVersion(unsigned char *bytes)
{
	unsigned char abi_version = ((Elf64_Ehdr *) bytes)->e_ident[EI_ABIVERSION];

	printf("  ABI Version:                       %d\n", abi_version);
}

/**
 * printType - Print elf type
 * @bytes: character array
 * @endianess: LSB or MSB
 */
void printType(unsigned char *bytes, int endianess)
{
	uint16_t type = ((Elf64_Ehdr *) bytes)->e_type;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &type, 2);
	printf("  Type:                              ");
	switch (type)
	{
	case ET_NONE:
		puts("NONE (None)");
		break;
	case ET_REL:
		puts("REL (Relocatable file)");
		break;
	case ET_EXEC:
		puts("EXEC (Executable file)");
		break;
	case ET_DYN:
		puts("DYN (Shared object file)");
		break;
	case ET_CORE:
		puts("CORE (Core file)");
		break;
	default:
		puts("Unknown type");
		break;
	}
}

/**
 * printFileVersion - Print file version
 * @bytes: character array
 * @endianess: LSB or MSB
 */
void printFileVersion(unsigned char *bytes, int endianess)
{
	uint16_t file_version = ((Elf64_Ehdr *) bytes)->e_version;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &file_version, 2);

	printf("  Version:                           ");

	switch (file_version)
	{
	case EV_NONE:
		/* puts("Invalid version"); */
		/* break; */
	case EV_CURRENT:
		puts("0x1");
		break;
	default:
		printf("%#x\n", file_version);
	}

}

/**
 * printEntryPoint - Print entry point address
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printEntryPoint(unsigned char *bytes, int class, int endianess)
{
	Elf64_Addr *entry64;
	Elf32_Addr *entry32;

	printf("  Entry point address:               ");
	if (class == ELFCLASS32)
	{
		entry32 = &((Elf32_Ehdr *) bytes)->e_entry;
		if (endianess == ELFDATA2MSB)
			reverse((unsigned char *) entry32, 4);
		printf("0x%x\n", *entry32);

	}
	else
	{
		entry64 = &((Elf64_Ehdr *) bytes)->e_entry;
		if (endianess == ELFDATA2MSB)
			reverse((unsigned char *) entry64, 8);
		printf("0x%lx\n", *entry64);

	}
}

/**
 * printProgramHeaders - Print program headers
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 */
void printProgramHeaders(unsigned char *bytes, int class, int endianess)
{
	Elf64_Off *headers64;
	Elf32_Off *headers32;

	printf("  Start of program headers:          ");
	if (class == ELFCLASS32)
	{
		headers32 = &((Elf32_Ehdr *) bytes)->e_phoff;
		if (endianess == ELFDATA2MSB)
			reverse((unsigned char *) headers32, 4);
		printf("%u", *headers32);

	}
	else
	{
		headers64 = &((Elf64_Ehdr *) bytes)->e_phoff;
		if (endianess == ELFDATA2MSB)
			reverse((unsigned char *) headers64, 8);
		printf("%lu", *headers64);

	}
	puts(" (bytes into file)");
}

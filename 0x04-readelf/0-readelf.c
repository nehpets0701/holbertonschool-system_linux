#include "elfs.h"

/**
*main-main
*Return:0 hopefully
*@argc:ac
*@argv:av
*/
int main(int argc, char **argv)
{
	unsigned char bytes[64];

	if (argc != 2)
		return (EXIT_SUCCESS);
	if (access(argv[1], F_OK) == -1)
	{
		fprintf(stderr, "readelf: Error: '%s': No such file\n", argv[1]);
		return (EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) == -1)
	{
		fprintf(stderr,
			"readelf: Error: %s: Failed to read file's magic number\n",
			argv[1]);
		return (EXIT_FAILURE);
	}
	if (read_elf_header_bytes(bytes, argv[1]))
	{
		perror("readelf: Error: ");
		return (EXIT_FAILURE);
	}
	if (check_elf(bytes))
		return (EXIT_FAILURE);
	printHeader(bytes,
		     bytes[4] == ELFCLASS32 ? ELFCLASS32 : ELFCLASS64,
		     bytes[5] == ELFDATA2MSB ? ELFDATA2MSB : ELFDATA2LSB);
	return (0);
}

/**
*printHeader-prints elf header
*@bytes:bytes
*@class:class
*@endianess:endianess
*/
void printHeader(unsigned char *bytes, int class, int endianess)
{
	printf("ELF Header:\n");
	printMagic(bytes);
	printClass(bytes);
	printData(bytes);
	printVersion(bytes);
	printOsabi(bytes);
	printAbiVersion(bytes);
	printType(bytes, endianess);
	printMachine(bytes, endianess);
	printFileVersion(bytes, endianess);
	printEntryPoint(bytes, class, endianess);
	printProgramHeaders(bytes, class, endianess);
	printSectionHeaders(bytes, class, endianess);
	printFlags(bytes, class, endianess);
	printHeaderSize(bytes, class, endianess);
	printProgramHeaderSize(bytes, class, endianess);
	printNumProgramHeaders(bytes, class, endianess);
	printSectionHsize(bytes, class, endianess);
	printNumSectionHeaders(bytes, class, endianess);
	printStrTable(bytes, class, endianess);
}

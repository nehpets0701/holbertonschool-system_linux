#include "elfs.h"

/**
 * printSectionHeaderLoop - Print info about section headers
 * reads each section in a loop
 * @bytes: character array
 * @class: ELFCLASS32 or ELFCLASS64
 * @endianess: LSB or MSB
 * @n_sections: number of sections
 * @header_size: size of section header
 * @str_table: string table section, .shtstrtab
 */
void printSectionHeaderLoop(unsigned char *bytes, int class, int endianess,
			       int n_sections, int header_size, unsigned char *str_table)
{
	int i;

	printSectionHeaderNames(class);

	for (i = 0; i < n_sections; ++i, bytes += header_size)
	{
		printf("  [%2d] ", i);
		printSectionName(bytes, class, endianess, str_table);
		printSectionType(bytes, class, endianess);
		printSectionAddr(bytes, class, endianess);
		printSectionOff(bytes, class, endianess);
		printSectionSize(bytes, class, endianess);
		printSectionEs(bytes, class, endianess);
		printSectionFlg(bytes, class, endianess);
		printSectionLk(bytes, class, endianess);
		printSectionInf(bytes, class, endianess);
		printSectionAl(bytes, class, endianess);
	}

	printKeyToFlags(class);
}

/**
 * printSectionHeaders - Print info about section headers, like readelf -S -W
 * @bytes: character array
 * @filename: elf file
 * @class: ELFCLASS32 or ELFCLASS64 (32 or 64 bit)
 * @endianess: LSB or MSB
 */
void printSectionHeader(unsigned char *bytes, char *filename, int class,
			  int endianess)
{
	void *p = get_section_header_off(bytes, class, endianess);
	Elf64_Off offset = class == ELFCLASS32 ? *(Elf32_Off *) p : *(Elf64_Off *) p;
	uint16_t n_sections = get_num_section_headers(bytes, class, endianess);
	uint16_t header_size = get_section_hsize(bytes, class, endianess);
	unsigned char *data = NULL, *str_table = NULL;
	size_t s_off, s_size;
	uint16_t shstrndx;

	printf("There are %d section headers, starting at offset %#lx:\n\n",
	       n_sections, offset);

	if (readBytes(&data, filename, offset, n_sections * header_size))
	{
		exit(EXIT_FAILURE);
	}

	shstrndx = get_string_table_idx(bytes, class, endianess);
	s_off = get_section_off(data + (shstrndx * header_size), class, endianess);
	s_size = get_section_size(data + (shstrndx * header_size), class, endianess);

	if (readBytes(&str_table, filename, s_off, s_size))
	{
		free(data);
		exit(EXIT_FAILURE);
	}
	printSectionHeaderLoop(data, class, endianess,
				  n_sections, header_size, str_table);
	free(data);
	free(str_table);
}

/**
 * main - Entry point, output is similar to readelf -S -W
 * prints section header
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 otherwise
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
	printSectionHeader(bytes, argv[1],
			 bytes[4] == ELFCLASS32 ? ELFCLASS32 : ELFCLASS64,
			 bytes[5] == ELFDATA2MSB ? ELFDATA2MSB : ELFDATA2LSB);
	return (0);
}

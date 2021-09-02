#ifndef ELF_H
#define ELF_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <stdlib.h>

void printHeader(unsigned char *bytes, int class, int endianess);
void printMagic(unsigned char *bytes);
void printStrTable(unsigned char *bytes, int class, int endianess);
void printClass(unsigned char *bytes);
void printData(unsigned char *bytes);
void printVersion(unsigned char *bytes);
void printOsabi(unsigned char *bytes);
void printOsabi2(unsigned char osabi);
void printMachine(unsigned char *bytes, int endianess);
void printMachine2(uint16_t machine);
void printMachine3(uint16_t machine);
void printAbiVersion(unsigned char *bytes);
void printType(unsigned char *bytes, int endianess);
void printFileVersion(unsigned char *bytes, int endianess);
void printEntryPoint(unsigned char *bytes, int class, int endianess);
void printProgramHeaders(unsigned char *bytes, int class, int endianess);
void printSectionHeaders(unsigned char *bytes, int class, int endianess);
void printFlags(unsigned char *bytes, int class, int endianess);
void printHeaderSize(unsigned char *bytes, int class, int endianess);
void printProgramHeaderSize(unsigned char *bytes, int class, int endianess);
void printNumProgramHeaders(unsigned char *bytes, int class, int endianess);
void printSectionHsize(unsigned char *bytes, int class, int endianess);
void printProgramHeaderSize(unsigned char *bytes, int class, int endianess);
void printNumSectionHeaders(unsigned char *bytes, int class, int endianess);

void printSectionName(unsigned char *data, int class, int endianess,
			unsigned char *str_table);
void printSectionAddr(unsigned char *data, int class, int endianess);
void printSectionOff(unsigned char *data, int class, int endianess);
void printSectionSize(unsigned char *data, int class, int endianess);
void printSectionEs(unsigned char *data, int class, int endianess);
/*static char *getSectionTypeName2(uint32_t type);
static char *getSectionTypeName(uint32_t type);*/
void printSectionType(unsigned char *data, int class, int endianess);
void printSectionFlg(unsigned char *data, int class, int endianess);
void printSectionLk(unsigned char *data, int class, int endianess);
void printSectionInf(unsigned char *data, int class, int endianess);
void printSectionAl(unsigned char *data, int class, int endianess);
void printSectionHeaderNames(int class);
void printKeyToFlags(int class);

void reverse(unsigned char *bytes, size_t size);
int read_elf_header_bytes(unsigned char *bytes, const char *filename);
int check_elf(unsigned char *bytes);
void *get_section_header_off(unsigned char *bytes, int class, int endianess);
Elf64_Off get_section_off(unsigned char *bytes, int class, int endianess);
uint64_t get_section_size(unsigned char *bytes, int class, int endianess);
uint16_t get_section_hsize(unsigned char *bytes, int class, int endianess);
uint16_t get_string_table_idx(unsigned char *bytes, int class, int endianess);
int readBytes(unsigned char **bytes, const char *filename, size_t offset,
	       size_t size);
uint16_t get_num_section_headers(unsigned char *bytes, int class,
				 int endianess);

void check_type(unsigned char *bytes, int endianess);
void print_program_header(unsigned char *bytes, char *filename, int class,
			  int endianess);
void print_segment_section_map(unsigned char *pheader, unsigned char *sheader,
			       unsigned char *strtab, int class, int endianess,
			       int ph_n, int ph_size, int sh_size, int sh_n);

void print_type_2(unsigned char *bytes, int endianess);
void print_entry_point_addr_2(unsigned char *bytes, int class, int endianess);
Elf64_Off get_ph_offset(unsigned char *bytes, int class, int endianess);
uint16_t get_program_header_size(unsigned char *bytes,
				 int class, int endianess);
uint16_t get_num_program_headers(unsigned char *bytes,
				 int class, int endianess);
void print_program_header_string(int class);
int print_pheader_type(unsigned char *pheader, int class, int endianess);
void print_pheader_offset(unsigned char *pheader, int class, int endianess);
Elf64_Off get_pheader_offset(unsigned char *pheader, int class, int endianess);
void print_pheader_vaddr(unsigned char *pheader, int class, int endianess);
Elf64_Off get_pheader_vaddr(unsigned char *pheader, int class, int endianess);
void print_pheader_paddr(unsigned char *pheader, int class, int endianess);
void print_pheader_fsize(unsigned char *pheader, int class, int endianess);
uint64_t get_pheader_fsize(unsigned char *pheader, int class, int endianess);
void print_pheader_align(unsigned char *pheader, int class, int endianess);
Elf64_Off get_program_offset(unsigned char *pheader, int class, int endianess);
void print_pheader_flg(unsigned char *pheader, int class, int endianess);
void print_pheader_msize(unsigned char *pheader, int class, int endianess);
uint64_t get_pheader_memsz(unsigned char *pheader, int class, int endianess);
void print_interpreter(unsigned char *pheader, int class, int endianess,
		       char *filename);
void print_pheader_loop(unsigned char *pheader, int class, int endianess,
			uint16_t n_pheader, uint16_t header_size, char *filename);
void print_section_name_2(unsigned char *data, int class, int endianess,
			  unsigned char *str_table);
Elf64_Addr get_section_addr(unsigned char *data, int class, int endianess);
uint64_t get_sh_size(unsigned char *data, int class, int endianess);
#endif

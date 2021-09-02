#include "elfs.h"

/**
 * printOsabi - Print osabi
 * @bytes: character array
 */
void printOsabi(unsigned char *bytes)
{
	unsigned char osabi = ((Elf64_Ehdr *) bytes)->e_ident[EI_OSABI];

	printf("  OS/ABI:                            ");
	switch (osabi)
	{
	case ELFOSABI_SYSV: /* Also ELFOSABI_NONE */
		puts("UNIX - System V");
		break;
	case ELFOSABI_HPUX:
		puts("UNIX - HP-UX");
		break;
	case ELFOSABI_NETBSD:
		puts("UNIX - NetBSD");
		break;
	case ELFOSABI_LINUX:
		puts("UNIX - GNU");
		break;
	case ELFOSABI_SOLARIS:
		puts("UNIX - Solaris");
		break;
	case ELFOSABI_IRIX:
		puts("UNIX - IRIX");
		break;
	case ELFOSABI_FREEBSD:
		puts("UNIX - FreeBSD");
		break;
	default:
		printOsabi2(osabi);
		break;
	}
}

/**
 * printOsabi2 - Print osabi
 * @osabi: osabi
 */
void printOsabi2(unsigned char osabi)
{
	switch (osabi)
	{
	case ELFOSABI_TRU64:
		puts("UNIX - TRU64");
		break;
	case ELFOSABI_MODESTO:
		puts("Novell Modesto");
		break;
	case ELFOSABI_OPENBSD:
		puts("OpenBSD");
		break;
	case ELFOSABI_ARM_AEABI:
		puts("ARM EABI");
		break;
	case ELFOSABI_ARM:
		puts("ARM");
		break;
	case ELFOSABI_STANDALONE:
		puts("Stand-alone (embedded)");
		break;
	default:
		printf("<unknown: %x>\n", osabi);
		break;
	}
}

/**
 * printMachine3 - Print machine architecture
 * @machine: machine architecture
 */
void printMachine3(uint16_t machine)
{
	switch (machine)
	{
	case EM_X86_64:
		puts("Advanced Micro Devices X86-64");
		break;
	case EM_VAX:
		puts("Stand-alone (embedded)");
		break;
	case EM_FAKE_ALPHA:
		puts("Alpha");
		break;
	case EM_AARCH64:
		puts("AArch64");
		break;
	default:
		printf("%d\n", machine);
		break;
	}
}

/**
 * printMachine2 - Print machine architecture
 * @machine: machine architecture
 */
void printMachine2(uint16_t machine)
{
	switch (machine)
	{
	case EM_PARISC:
		puts("HPPA");
		break;
	case EM_SPARC32PLUS:
		puts("Sparc v8+");
		break;
	case EM_PPC:
		puts("PowerPC");
		break;
	case EM_PPC64:
		puts("PowerPC 64-bit");
		break;
	case EM_S390:
		puts("IBM S/390");
		break;
	case EM_ARM:
		puts("ARM");
		break;
	case EM_SH:
		puts("Renesas / SuperH SH");
		break;
	case EM_SPARCV9:
		puts("SPARC v9 64-bit");
		break;
	case EM_IA_64:
		puts("Intel IA-64");
		break;
	default:
		printMachine3(machine);
		break;
	}
}

/**
 * printMachine - Print machine architecture
 * @bytes: character array
 * @endianess: LSB or MSB
 */
void printMachine(unsigned char *bytes, int endianess)
{
	uint16_t machine = ((Elf64_Ehdr *) bytes)->e_machine;

	if (endianess == ELFDATA2MSB)
		reverse((unsigned char *) &machine, 2);
	printf("  Machine:                           ");
	switch (machine)
	{
	case EM_NONE:
		puts("An unknown machine");
		break;
	case EM_M32:
		puts("AT&T WE 32100");
		break;
	case EM_SPARC:
		puts("Sparc");
		break;
	case EM_386:
		puts("Intel 80386");
		break;
	case EM_68K:
		puts("Motorola 68000");
		break;
	case EM_88K:
		puts("Motorola 88000");
		break;
	case EM_860:
		puts("Intel 80860");
		break;
	case EM_MIPS:
		puts("MIPS R3000");
		break;
	default:
		printMachine2(machine);
	}
}

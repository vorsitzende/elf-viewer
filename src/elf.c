/* ELF.C - ELF File Processing Functions.
 * Claudia Jughashvili, 2019
 */

#include <elf.h>
#include <stdio.h>

const char* abi_string (enum ABI abi) {
  static const char* ABI_STRINGS[] = {
    "System V", "HP UX", "NetBSD", "Linux", "GNU Hurd", "Solaris", "AIX",
    "IRIX", "FreeBSD", "Tru64", "Novell Modesto", "OpenBSD", "OpenVMS",
    "NonStop Kernel", "AROS", "Fenix OS", "Cloud ABI"
  };
  return ABI_STRINGS[abi];
};

const char* elf_type_string (enum E_TYPE type) {
  static const char* E_TYPE_STRINGS[] = {
    "None", "Relocatable", "Executable", "Dynamic", "Core", "Low-mem OS",
    "High-mem OS", "Low-processing", "High-processing"
  };
  unsigned int index = 0;

  switch (type) {
    case ET_LOOS:
      index = 5;
      break;
    case ET_HIOS:
      index = 6;
      break;
    case ET_LOPROC:
      index = 7;
      break;
    case ET_HIPROC:
      index = 8;
      break;
    default:
      index = type;
  };
  return E_TYPE_STRINGS[index];
};

const char* machine_string (enum E_MACHINE machine) {
  static const char* E_MACHINE_STRINGS[] = {
    "None", "Sparc", "x86", "MIPS", "PowerPC", "S390", "ARM", "SuperH",
    "IA 64", "x86_64", "AArch64", "RISC V"
  };
  unsigned int index = 0;

  switch (machine) {
    case EM_NONE:
      index = 0;
      break;
    case EM_SPARC:
      index = 1;
      break;
    case EM_X86:
      index = 2;
      break;
    case EM_MIPS:
      index = 3;
      break;
    case EM_POWERPC:
      index = 4;
      break;
    case EM_S390:
      index = 5;
      break;
    case EM_ARM:
      index = 6;
      break;
    case EM_SUPERH:
      index = 7;
      break;
    case EM_IA_64:
      index = 8;
      break;
    case EM_X86_64:
      index = 9;
      break;
    case EM_AARCH64:
      index = 10;
      break;
    case EM_RISC_V:
      index = 11;
  };
  return E_MACHINE_STRINGS[index];
};

const struct ELF32_HEADER* load_elf_file (const char* path) {
  static unsigned char buffer[55];
  FILE* file = fopen (path, "rb");
  if (file)
    fread (buffer, sizeof (buffer), 1, file);
  fclose (file);
  return (struct ELF32_HEADER*)buffer;
};

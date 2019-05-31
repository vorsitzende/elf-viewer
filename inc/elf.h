/* ELF.H - ELF File Declarations and Functions.
 * Claudia Jughashvili, 2019
 */

#ifndef _ELF_H_
#define _ELF_H_

#include <stdint.h>

enum ABI {
  ABI_SYSTEM_V, ABI_HP_UX, ABI_NETBSD, ABI_LINUX, ABI_GNU_HURD, ABI_SOLARIS,
  ABI_AIX, ABI_IRIX, ABI_FREEBSD, ABI_TRU64, ABI_NOVELL_MODESTO, ABI_OPENBSD,
  ABI_OPENVMS, ABI_NONSTOP_KERNEL, ABI_AROS, ABI_FENIX_OS, ABI_CLOUD_ABI
};

enum E_TYPE {
  ET_NONE, ET_REL, ET_EXEC, ET_DYN, ET_CORE,
  ET_LOOS = 0xFE00,
  ET_HIOS = 0xFEFF,
  ET_LOPROC = 0xFF00,
  ET_HIPROC = 0xFFFF
};

enum E_MACHINE {
  EM_NONE = 0x00,
  EM_SPARC = 0x02,
  EM_X86 = 0x03,
  EM_MIPS = 0x08,
  EM_POWERPC = 0x14,
  EM_S390 = 0x16,
  EM_ARM = 0x28,
  EM_SUPERH = 0x2A,
  EM_IA_64 = 0x32,
  EM_X86_64 = 0x3E,
  EM_AARCH64 = 0xB7,
  EM_RISC_V = 0xF3
};

struct ELF32_HEADER {
  union {
    uint32_t magic_number;
    struct { uint8_t mn1, mn2, mn3, mn4; } sub_number;
  } MAGIC;
  uint8_t ei_class, ei_data, ei_version, ei_osabi, ei_abiversion;
  uint8_t pad_1, pad_2, pad_3, pad_4, pad_5, pad_6, pad_7;
  uint16_t e_type, e_machine;
  uint32_t e_version, e_entry, e_phoff, e_shoff, e_flags;
  uint16_t e_ehsize, e_phentsize, e_phnum, e_shentsize, e_shnum, e_shstrndx;
};

struct PHEADER {
  uint32_t p_type, p_offset, p_vaddr, p_addr, p_filesz, p_memsz, p_flags,
    p_align;
};

struct SHEADER {
  uint32_t sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size, sh_link,
    sh_info, sh_addralign, sh_entsize;
};

#ifdef __cplusplus
extern "C" {
#endif

  const char* abi_string (enum ABI);
  const char* elf_type_string (enum E_TYPE);
  const char* machine_string (enum E_MACHINE);
  const struct ELF32_HEADER* load_elf_file (const char*);

#ifdef __cplusplus
};
#endif

#endif /* _ELF_H_ */

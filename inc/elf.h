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
  ET_LOOS =     0xFE00,
  ET_HIOS =     0xFEFF,
  ET_LOPROC =   0xFF00,
  ET_HIPROC =   0xFFFF
};

enum E_MACHINE {
  EM_NONE =     0x00,
  EM_SPARC =    0x02,
  EM_X86 =      0x03,
  EM_MIPS =     0x08,
  EM_POWERPC =  0x14,
  EM_S390 =     0x16,
  EM_ARM =      0x28,
  EM_SUPERH =   0x2A,
  EM_IA_64 =    0x32,
  EM_X86_64 =   0x3E,
  EM_AARCH64 =  0xB7,
  EM_RISC_V =   0xF3
};

enum P_TYPE {
  PT_NULL =     0x00,
  PT_LOAD =     0x01,
  PT_DYNAMIC =  0x02,
  PT_INTERP =   0x03,
  PT_NOTE =     0x04,
  PT_SHILB =    0x05,
  PT_PHDR =     0x06,
  PT_LOOS =     0x60000000,
  PT_HIOS =     0x6FFFFFFF,
  PT_LOPROC =   0x70000000,
  PT_HIPROC =   0x7FFFFFFF
};

enum SH_TYPE {
  SHT_NULL, SHT_PROGBITS, SHT_SYMTAB, SHT_STRTAB, SHT_RELA, SHT_HASH,
  SHT_DYNAMIC, SHT_NOTE, SHT_NOBITS, SHT_REL, SHT_SHLIB, SHT_DYNSYM,
  SHT_INIT_ARRAY, SHT_FINI_ARRAY, SHT_PREINIT_ARRAY, SHT_GROUP,
  SHT_SYMTAB_SHNDX, SHT_NUM
};

enum SH_FLAGS {
  SHF_WRITE =             0x1,
  SHF_ALLOC =             0x3,
  SHF_EXECINSTR =         0x4,
  SHF_MERGE =             0x10,
  SHF_STRINGS =           0x20,
  SHF_INFO_LINK =         0x40,
  SHF_LINK_ORDER =        0x80,
  SHF_OS_NONCONFORMING =  0x100,
  SHF_GROUP =             0x200,
  SHF_TLS =               0x400,
  SHF_MASKOS =            0x0FF00000,
  SHF_MASKPROC =          0xF0000000,
  SHF_ORDERED =           0x40000000,
  SHF_EXCLUDE =           0x80000000
};

struct ELF32_HEADER {
  uint32_t ei_ident;
  uint8_t ei_class, ei_data, ei_version, ei_osabi, ei_abiversion;
  uint8_t pad_1, pad_2, pad_3, pad_4, pad_5, pad_6, pad_7;
  uint16_t e_type, e_machine;
  uint32_t e_version, e_entry, e_phoff, e_shoff, e_flags;
  uint16_t e_ehsize, e_phentsize, e_phnum, e_shentsize, e_shnum, e_shstrndx;
};

struct ELF64_HEADER {
  uint32_t ei_ident;
  uint8_t ei_class, ei_data, ei_version, ei_osabi, ei_abiversion;
  uint8_t pad_1, pad_2, pad_3, pad_4, pad_5, pad_6, pad_7;
  uint16_t e_type, e_machine;
  uint32_t e_version;
  uint64_t e_entry, e_phoff, e_shoff;
  uint32_t e_flags;
  uint16_t e_ehsize, e_phentsize, e_phnum, e_shentsize, e_shnum, e_shstrndx;
};

struct PHEADER32 {
  uint32_t p_type, p_offset, p_vaddr, p_addr, p_filesz, p_memsz, p_flags,
    p_align;
};

struct PHEADER64 {
  uint32_t p_type, p_flags;
  uint64_t p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align;
};

struct SHEADER32 {
  uint32_t sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size, sh_link,
    sh_info, sh_addralign, sh_entsize;
};

struct SHEADER64 {
  uint32_t sh_name, sh_type;
  uint64_t sh_flags, sh_addr, sh_offset, sh_size;
  uint32_t sh_link, sh_info;
  uint64_t sh_addralign, sh_entsize;
};

#ifdef __cplusplus
extern "C" {
#endif

  const char* abi_string (enum ABI);
  const char* elf_type_string (enum E_TYPE);
  const char* machine_string (enum E_MACHINE);
  const char* program_type_string (enum P_TYPE);
  const struct ELF32_HEADER* load_elf_file (const char*);
  unsigned int magic_number (void);

#ifdef __cplusplus
};
#endif

#endif /* _ELF_H_ */

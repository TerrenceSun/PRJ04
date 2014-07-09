#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "libbfd.h"
//must include for struct define, such as elf_backend_data
//Also, put a entry for upu in elf_target_id (UPU_ELF_DATA) or use a generic
#include "elf-bfd.h"
#include "elf/upu.h"

static void
upu_elf_info_to_howto (bfd * abfd ATTRIBUTE_UNUSED,
			      arelent * cache_ptr ATTRIBUTE_UNUSED,
			      Elf_Internal_Rela * dst ATTRIBUTE_UNUSED)
{
}

static reloc_howto_type *
upu_elf_reloc_type_lookup (bfd * abfd ATTRIBUTE_UNUSED,
				  bfd_reloc_code_real_type code ATTRIBUTE_UNUSED)
{
	return NULL;
}

static reloc_howto_type *
upu_elf_reloc_name_lookup (bfd *abfd ATTRIBUTE_UNUSED,
				  const char *r_name ATTRIBUTE_UNUSED)
{
    return NULL;
}
#define TARGET_BIG_SYM      bfd_elf32_upu_vec
#define TARGET_BIG_NAME		"elf32-upu"

#define ELF_ARCH		    bfd_arch_upu
#define ELF_TARGET_ID		UPU_ELF_DATA
//EM_UPU is defined in elf/common.h
#define ELF_MACHINE_CODE	EM_UPU
//No memory management for UPU, so set it to 1
#define ELF_MAXPAGESIZE		0x1

#define elf_info_to_howto	upu_elf_info_to_howto

#define bfd_elf32_bfd_reloc_type_lookup		upu_elf_reloc_type_lookup
#define bfd_elf32_bfd_reloc_name_lookup		upu_elf_reloc_name_lookup

#include "elf32-target.h"

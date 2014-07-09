#ifndef TC_UPU
#define TC_UPU 1

#include "write.h"        /* For definition of fixS */

#define TARGET_ARCH bfd_arch_upu
#define TARGET_FORMAT "elf32-upu"
#define TARGET_BYTES_BIG_ENDIAN 1

/* Want the section information too... */
#define MD_PCREL_FROM_SECTION(FIXP, SEC) md_pcrel_from_section (FIXP, SEC)

extern void      md_begin            (void);
extern int       md_parse_option     (int, char *);
extern void      md_show_usage       (FILE *);
extern void      md_number_to_chars  (char *, valueT, int);
extern void      md_operand          (expressionS *);
extern char *    md_atof             (int, char *, int *);
extern symbolS * md_undefined_symbol (char *);
extern void      md_assemble         (char *);
extern valueT    md_section_align    (segT, valueT);
extern void      md_convert_frag     (bfd *, segT, fragS *);
extern arelent * tc_gen_reloc        (asection *, fixS *);
extern long      md_pcrel_from_section         (fixS *, segT);
extern int       md_estimate_size_before_relax (fragS *, segT);

#endif /* TC_UPU */

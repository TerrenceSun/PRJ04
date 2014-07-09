#include "as.h"
#include <stdio.h>
#include "bfd.h"
#include "subsegs.h"
#define DEFINE_TABLE
//#include "../opcodes/microblaze-opc.h"
//#include "../opcodes/microblaze-opcm.h"
#include "safe-ctype.h"
#include <string.h>
#include <dwarf2dbg.h>
#include "aout/stab_gnu.h"
const char comment_chars[] = "#";
const char line_comment_chars[] = "#";
const char line_separator_chars[] = ";";
const char EXP_CHARS[] = "eE";
/* Chars that mean this number is a floating point constant
   As in 0f12.456
   or    0d1.2345e12.  */
const char FLT_CHARS[] = "rRsSfFdDxXpP";

/* This table describes all the machine specific pseudo-ops the assembler
   has to support.  The fields are:
   Pseudo-op name without dot
   Function to call to execute this pseudo-op
   Integer arg to pass to the function.  */
/* If the pseudo-op is not found in this table, it searches in the obj-elf.c,
   and then in the read.c table.  */
const pseudo_typeS md_pseudo_table[] =
{
  {NULL, NULL, 0}
};

const char * md_shortopts = "";
struct option md_longopts[] =
{
  { NULL,          no_argument, NULL, 0}
};

size_t md_longopts_size = sizeof (md_longopts);

static struct hash_control * opcode_hash_control;   /* Opcode mnemonics.  */

int
md_parse_option (int c ATTRIBUTE_UNUSED, char * arg ATTRIBUTE_UNUSED)
{
  return 0;
}

void
md_show_usage (FILE * stream ATTRIBUTE_UNUSED)
{
  fprintf(stream, _(" No usage for UPU\n"));
}

void
md_begin (void)
{
  //struct op_code_struct * opcode;

  opcode_hash_control = hash_new ();
    //TODO implement the opcode
  /* Insert unique names into hash table.  */
  /*for (opcode = opcodes; opcode->name; opcode ++)
    hash_insert (opcode_hash_control, opcode->name, (char *) opcode);*/
}

void
md_number_to_chars (char * ptr, valueT use, int nbytes)
{
  if (target_big_endian)
    number_to_chars_bigendian (ptr, use, nbytes);
  else
    number_to_chars_littleendian (ptr, use, nbytes);
}

void
md_operand (expressionS * expressionP)
{
  /* Ignore leading hash symbol, if present.  */
  if (*input_line_pointer == '#')
    {
      input_line_pointer ++;
      expression (expressionP);
    }
}
/* Various routines to kill one day.  */
/* Equal to MAX_PRECISION in atof-ieee.c */
#define MAX_LITTLENUMS 6

/* Turn a string in input_line_pointer into a floating point constant of type
   type, and store the appropriate bytes in *litP.  The number of LITTLENUMS
   emitted is stored in *sizeP.  An error message is returned, or NULL on OK.*/
char *
md_atof (int type, char * litP, int * sizeP)
{
  int prec;
  LITTLENUM_TYPE words[MAX_LITTLENUMS];
  int    i;
  char * t;

  switch (type)
  {
      case 'f':
      case 'F':
      case 's':
      case 'S':
          prec = 2;
          break;
      default:
          *sizeP = 0;
          return _("Bad call to MD_NTOF()");
  }

  t = atof_ieee (input_line_pointer, type, words);

  if (t)
    input_line_pointer = t;

  *sizeP = prec * sizeof (LITTLENUM_TYPE);

  if (! target_big_endian)
    {
      for (i = prec - 1; i >= 0; i--)
        {
          md_number_to_chars (litP, (valueT) words[i],
                              sizeof (LITTLENUM_TYPE));
          litP += sizeof (LITTLENUM_TYPE);
        }
    }
  else
    for (i = 0; i < prec; i++)
      {
        md_number_to_chars (litP, (valueT) words[i],
                            sizeof (LITTLENUM_TYPE));
        litP += sizeof (LITTLENUM_TYPE);
      }

  return NULL;
}

symbolS *
md_undefined_symbol (char * name ATTRIBUTE_UNUSED)
{
  return NULL;
}

int md_short_jump_size;

void
md_create_short_jump (char * ptr ATTRIBUTE_UNUSED,
              addressT from_Nddr ATTRIBUTE_UNUSED,
              addressT to_Nddr ATTRIBUTE_UNUSED,
              fragS * frag ATTRIBUTE_UNUSED,
              symbolS * to_symbol ATTRIBUTE_UNUSED)
{
  as_fatal (_("failed sanity check: short_jump"));
}

int md_long_jump_size;

void
md_create_long_jump (char * ptr ATTRIBUTE_UNUSED,
              addressT from_Nddr ATTRIBUTE_UNUSED,
              addressT to_Nddr ATTRIBUTE_UNUSED,
              fragS * frag ATTRIBUTE_UNUSED,
              symbolS * to_symbol ATTRIBUTE_UNUSED)
{
  as_fatal (_("failed sanity check: short_jump"));
}

void
md_assemble (char * str)
{
    as_warn(str);
    return;
}

valueT
md_section_align (segT segment ATTRIBUTE_UNUSED, valueT size)
{
  return size;          /* Byte alignment is fine.  */
}

/* Called after relaxing, change the frags so they know how big they are.  */

void
md_convert_frag (bfd * abfd ATTRIBUTE_UNUSED,
             segT sec ATTRIBUTE_UNUSED,
         fragS * fragP ATTRIBUTE_UNUSED)
{
}

arelent *
tc_gen_reloc (asection * section ATTRIBUTE_UNUSED, fixS * fixp ATTRIBUTE_UNUSED)
{
    return NULL;
}
/* The location from which a PC relative jump should be calculated,
   given a PC relative reloc.  */

long
md_pcrel_from_section (fixS * fixp ATTRIBUTE_UNUSED, segT sec ATTRIBUTE_UNUSED)
{
    return 0;
}

/* Applies the desired value to the specified location.
   Also sets up addends for 'rela' type relocations.  */
void
md_apply_fix (fixS *   fixP ATTRIBUTE_UNUSED,
          valueT * valp ATTRIBUTE_UNUSED,
          segT     segment ATTRIBUTE_UNUSED)
{
}
/* Called just before address relaxation, return the length
   by which a fragment must grow to reach it's destination.  */

int
md_estimate_size_before_relax (fragS * fragP ATTRIBUTE_UNUSED,
                   segT segment_type ATTRIBUTE_UNUSED)
{
    return 0;
}

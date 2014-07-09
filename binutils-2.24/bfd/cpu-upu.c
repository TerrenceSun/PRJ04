#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

const bfd_arch_info_type bfd_upu_arch =
{
  32,		  		/* 32 bits in a word.  */
  32,		  		/* 32 bits in an address.  */
  8,		  		/* 8 bits in a byte.  */
  bfd_arch_upu,     /* Architecture.  */
  0,		  		/* Machine number - 0 for now.  */
  "upu",	  		/* Architecture name.  */
  "upu",	  		/* Printable name.  */
  3,		  		/* Section align power.  */
  TRUE,		  		/* Is this the default architecture ?  */
  bfd_default_compatible,	/* Architecture comparison function.  */
  bfd_default_scan,	   	/* String to architecture conversion.  */
  bfd_arch_default_fill,	/* Default fill.  */
  NULL			   	/* Next in list.  */
};

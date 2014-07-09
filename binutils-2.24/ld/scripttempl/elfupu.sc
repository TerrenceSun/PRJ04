test -z "$ENTRY" && ENTRY=_start
cat <<EOF
OUTPUT_FORMAT("${OUTPUT_FORMAT}", "${BIG_OUTPUT_FORMAT}",
	      "${LITTLE_OUTPUT_FORMAT}")

_TEXT_START_ADDR = DEFINED(_TEXT_START_ADDR) ? _TEXT_START_ADDR : 0x50;		
_HEAP_SIZE = DEFINED(_HEAP_SIZE) ? _HEAP_SIZE : 0x0;
_STACK_SIZE = DEFINED(_STACK_SIZE) ? _STACK_SIZE : 0x0;

SECTIONS
{
  .text : {
    ${RELOCATING+*(.text)}
    ${RELOCATING+*(.text.*)}
    ${RELOCATING+*(.gnu.linkonce.t.*)}
  }

  .data : {
    ${RELOCATING+*(.data)}
    ${RELOCATING+*(.gnu.linkonce.d.*)}
    ${CONSTRUCTING+CONSTRUCTORS}; /* Is this needed? */
  }
}
EOF

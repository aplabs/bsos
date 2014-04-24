;	gdt.asm
;	Defines the Global Descriptor Table required by 32-bit protected mode
;	Author: William Woodruff, 2014

gdt_start:

gdt_null:
	dd 0x0
	dd 0x0

gdt_code:
	dw 0xffff
	dw 0x0
	db 0x0
	db 10011010b
	db 11001111b
	db 0x0

gdt_data:
	dw 0xffff
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0

gdt_end:

gdt_descriptor:
	dw gdt_end - gdt_start - 1
	dd gdt_start


; constants for segment descriptor offsets
CODE_SEGMENT equ gdt_code - gdt_start
DATA_SEGMENT equ gdt_data - gdt_start
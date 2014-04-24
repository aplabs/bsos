;	boot.asm
;	Bootstraps the system into 32-bit protected mode.
;	Author: William Woodruff, 2014

[org 0x7c00]

mov bp, 0x9000 ; set the (16-bit) stack safely
mov sp, bp

mov bx, REAL_MODE_MSG
call print_string_bios

call switch_to_pm

jmp $

%include "print_string_bios.asm"
%include "print_string_vga.asm"
%include "gdt.asm"
%include "switch_to_pm.asm"

[bits 32]

BEGIN_PM: ; referenced in switch_to_pm.asm
	mov ebx, PROT_MODE_MSG
	call print_string_vga

	jmp $ ; hang

; globals
REAL_MODE_MSG db "Starting in real mode...", 0
PROT_MODE_MSG db "Loaded 32-bit protected mode...", 0

times 510-($-$$) db 0
dw 0xaa55

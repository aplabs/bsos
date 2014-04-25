;	boot.asm
;	Bootstraps the system into 32-bit protected mode.
;	Authors: William Woodruff, Brian Hong 2014

[org 0x7c00]
KERNEL_OFFSET equ 0x1000

;some computers BIOS fucks up sometimes with ES register
mov ax, 0x0
mov es, ax

mov [BOOT_DRIVE], dl

mov bp, 0x9000 ; set the (16-bit) stack safely
mov sp, bp

mov bx, REAL_MODE_MSG
call print_string_bios

call load_kernel

call switch_to_pm

jmp $

%include "print_string_bios.asm"
%include "disk_load.asm"
%include "print_string_vga.asm"
%include "gdt.asm"
%include "switch_to_pm.asm"

[bits 16]
load_kernel:
	mov bx, KERN_LOAD_MSG
	call print_string_bios

	mov bx, KERNEL_OFFSET
	mov dh, 15 ; 15 sectors is more than enough
	mov dl, [BOOT_DRIVE]
	call disk_load
	ret

[bits 32]

BEGIN_PM: ; referenced in switch_to_pm.asm
	mov ebx, PROT_MODE_MSG
	call print_string_vga

	call KERNEL_OFFSET ; jump to the kernel in memory

	jmp $ ; hang

; globals
BOOT_DRIVE db 0
REAL_MODE_MSG db "Starting in real mode...", 0
PROT_MODE_MSG db "Loaded 32-bit protected mode...", 0
KERN_LOAD_MSG db "Loading kernel...", 0

times 510-($-$$) db 0
dw 0xaa55

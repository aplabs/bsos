;	print_string_vga.asm
;	Prints a null-terminated string to the screen using VGA and video memory.
;	Author: William Woodruff, 2014

[bits 32]

; globals
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f

; ebx - location of null-terminated string
print_string_vga:
	pusha
	mov edx, VIDEO_MEMORY

	.next:
	mov al, [ebx]
	mov ah, WHITE_ON_BLACK

	cmp al, 0
	je .done ; jump to done is the character is null

	mov [edx], ax

	inc ebx
	add edx, 2

	jmp .next

	.done:
	popa
	ret
;	print_string_bios.asm
;	Prints a null-terminated string using BIOS ISRs. Only works in 16-bit real mode.
;	Author: William Woodruff, 2014

; bx - location of the null-terminated string
print_string_bios:
	mov ah, 0x0e ; output
	.next:
	mov al, [bx] ; load a byte from bx
	inc bx ; increment to the next byte
	cmp al, 0
	je .done ; if the current byte is 0 (null), return
	int 0x10
	jmp .next
	.done:
	ret
;	disk_load.asm
;	Loads sectors from a given disk.
;	Author: William Woodruf, 2014

disk_load:
	push dx

	mov ah, 0x02 ; BIOS read sector ISR
	mov al, dh
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 0x02

	int 0x13 ; interrupt

	jc .disk_error

	pop dx
	cmp dh, al
	jne .disk_error
	ret

.disk_error:
	jmp $ ; hang
;	switch_to_pm.asm
;	Switches the processor to 32-bit protected mode, using the GDT
;	Author: William Woodruff, 2014

[bits 16]

switch_to_pm:
	cli ; disable interrupts
	lgdt [gdt_descriptor] ; from gdt.asm

	mov eax, cr0
	or eax, 0x1
	mov cr0, eax

	jmp CODE_SEGMENT:init_pm ; far jump to 32-bit code, flushing CPU pipeline

[bits 32]

init_pm:
	mov ax, DATA_SEGMENT
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov ebp, 0x90000 ; safely set the stack
	mov esp, ebp

	call BEGIN_PM
;	kern_entry.asm
;	Defines the entry point for the kernel (main)
;	Author: William Woodruff, 2014

[bits 32]
[extern main]

call main
jmp $ ; hang when kernel exits

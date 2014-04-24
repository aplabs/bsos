[bits 32]
[extern main]

call main
jmp $ ; hang when kernel exits
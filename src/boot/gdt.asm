;  Global Descriptor Table setup
;  All memory is allocated for code and data
;  Updated by Pawel to include significant information
;  

gdt_start:

 gdt_null:                  ;mandatory null descriptor
  
  dd 0x0
  dd 0x0

 gdt_code:
  
  dw 0xffff                ;Limit (bits 0-15)
  dw 0x0                   ;Base (Bits 0-15)
  db 0x0                   ;Base (bits 16-23)
  db 10011010b             ;(present)(privilege)()(descriptortype)|(1 for code, 0 for data)(conforming)(readable)(accessed)
  db 11001111b             ;(granularity)(16 bit/32 bit)(64 bit)(for system software) | Limit (bits 16-19)
  db 0x0                   ;Base (bits 24-31)

 gdt_data:

  dw 0xffff                ;This is identical to the code segment
  dw 0x0
  db 0x0
  db 10010010b             ;...... except for the 5th bit
  db 11001111b
  db 0x0

gdt_end:                   ;so assembler can calulate length of gdt



;GDT descriptor

gdt_descriptor:
 
 dw gdt_end - gdt_start - 1    ;Size of GDT, always one less than actual size
 dd gdt_start                  ;start of our GDT


;GDT segment descriptor offsets, this is what segment registers must contain in protected mode
;when DS = 0x10, CPU knows we want to use the segment at offset 0x10 (16bytes) in our GDT
;0x08 -> CODE
;0x10 -> DATA


DATA_SEG equ gdt_code - gdt_start
CODE_SEG equ gdt_data - gdt_start

all:
	gcc -ffreestanding -c src/kern/main.c -o main.o
	nasm src/kern/kern_entry.asm -f elf64 -o kern_entry.o
	ld -o kernel.bin -Ttext 0x1000 kern_entry.o main.o --oformat binary
	nasm src/boot/boot.asm -I 'src/boot/' -f bin -o boot.bin
	cat boot.bin kernel.bin > os-image
	rm *.o *.bin
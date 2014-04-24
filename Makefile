all:
	gcc -ffreestanding -std=gnu99 -c src/kern/main.c -o main.o
#	gcc -ffreestanding -c src/kern/main.c -o main.o # for 32 bit
	nasm src/kern/kern_entry.asm -f elf64 -o kern_entry.o
#	nasm src/kern/kern_entry.asm -f elf -o kern_entry.o # for 32 bit
	ld -o kernel.bin -Ttext 0x1000 kern_entry.o main.o --oformat binary
	nasm src/boot/boot.asm -I 'src/boot/' -f bin -o boot.bin
	cat boot.bin kernel.bin > os-image
	rm *.o *.bin

	ld -o kernel.bin -Ttext 0x1000 kern_entry.o main.o --oformat binary
	nasm src/boot/boot.asm -I 'src/boot/' -f bin -o boot.bin
	cat boot.bin kernel.bin > os-image
	rm *.o *.bin

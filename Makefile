CSRC=$(wildcard src/kern/*.c src/kern/drivers/*.c)
CHDR=$(wildcard src/kern/*.h src/kern/drivers/*.h)
OBJ=${CSRC:.c=.o}

all: os-image

os-image: boot.bin kernel.bin
	cat $^ > os-image

boot.bin:
	nasm src/boot/boot.asm -f bin -I 'src/boot/' -o $@

kernel.bin: kern_entry.o ${OBJ}
	ld -o $@ -Ttext 0x1000 $^ --oformat binary

%.o: %.c ${CHDR}
	gcc -ffreestanding -std=gnu99 -c $< -o $@

kern_entry.o:
	nasm src/kern/kern_entry.asm -f elf64 -o $@

clean:
	rm -rf *.bin *.o
	rm -rf src/kern/*.o 
	rm -rf src/kern/drivers/*.o
	rm -if os-image # ask to remove the image


OUT = "test"
OUT2 = "test2"

frame: frame.c
	gcc -g -O0 -o $(OUT) frame.c
	gcc -g -O2 -o $(OUT2) frame.c

fr: fr.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

address: address.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

addr: addr.c
	gcc -g -O0 -o $(OUT) addr.c

var: var.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

bss: bss.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

times: times.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

equ: equ.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

cmp: cmp.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

loop: loop.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

str: str.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

array: array.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

struct: struct.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

define: define.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

macro: macro.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o

libc: libc.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	gcc -no-pie -o $(OUT) $@.o

add: add.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	gcc -no-pie -o $(OUT) $@.o

clean:
	-rm *.o
	-rm $(OUT) $(OUT2)

.PHONY: clean
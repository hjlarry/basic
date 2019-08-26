OUT = "test"
OUT2 = "test2"

# frame: frame.c
# 	gcc -g -O0 -o $(OUT) frame.c
# 	gcc -g -O2 -o $(OUT2) frame.c

fr: fr.s
	nasm -g -F dwarf -f elf64 -o $@.o $<
	ld -o $(OUT) $@.o
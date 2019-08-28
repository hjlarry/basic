global _start

section .text

    _start:
        xor     rax, rax
        x       equ "abc"
        y       equ 0x3c
        z       equ $-$$

        mov     rax, x
        mov     rbx, y
        mov     rcx, z
        mov     rdx, x
        
        mov     rax, 60
        xor     rdi, rdi
        syscall
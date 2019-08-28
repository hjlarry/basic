global _start

section .bss
    x resq 2                 ; size = resq *2
    y resb 8                 ; size = resb *8
    leny equ $-y                



section .text

    _start:
        mov     rax, leny
        mov     qword [y], 0x1234
        
        mov     rax, 60
        xor     rdi, rdi
        syscall
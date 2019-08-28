global _start

section .data
    x times 3 dw 1,2     
    lenx equ $-x                

section .bss
    y times 2 resb 8
    leny equ $-y

section .text

    _start:
        mov     rax, lenx
        mov     rbx, leny
        
        mov     rax, 60
        xor     rdi, rdi
        syscall
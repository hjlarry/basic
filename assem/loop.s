global _start

section .text

    _start:
        xor     rax, rax
        mov     rcx, 3
    .loop:
        inc     rax
        loop    .loop

    .exit:
        mov     rax, 60
        xor     rdi, rdi
        syscall
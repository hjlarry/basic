global _start

section .text

    _start:
        mov     rax, 1
        mov     rbx, 2
        cmp     rax,rbx
        jne     .exit
        inc     rax

    .exit:
        mov     rax, 60
        xor     rdi, rdi
        syscall
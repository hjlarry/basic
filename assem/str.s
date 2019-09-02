global _start

section .rodata
    s   db  `\u6c49\xe5\xad\x97 \u263a \n`
    lens    equ     $-s

section .bss
    dst  resb    50

section .text
    _start:
        ; move
        mov     rsi, s
        mov     rdi, dst
        mov     rcx, lens
        rep     movsb

        ; print
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, dst
        mov     rdx, lens
        syscall

    .exit:
        mov     rax, 60
        xor     rdi, rdi
        syscall
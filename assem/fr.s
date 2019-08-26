global _start

section .data
    hello   : db `hello,world!\n`

section .text

    _start:
        mov     rax, 1
        test    rax, rax ; ZF=1 if AX==0 else ZF=0
        jne     .exit    ; jmp if ZF==0

    .hello:
        mov     rax, 1
        mov     rdi, 1
        mov     rsi, hello
        mov     rdx, 14
        syscall

    .exit:
        mov     rax, 60
        xor     rdi, rdi
        syscall
global _start


section .rodata
    hello db `hello world\n`
    length equ $-hello

section .text
    %macro DEMO 1
        mov   rax, %1
    %endmacro

    %macro DEMO 2
        mov   rax, %1
        mov   rbx, %2
    %endmacro

    %macro LABEL 1
        jmp    %%xxx
    %%xxx:
        mov    rax, %1
    %endmacro

    %macro PRINT 2
        mov    rax, 1
        mov    rdi, 1
        mov    rsi, %1
        mov    rdx, %2
        syscall
    %endmacro

    _start:
        PRINT   hello, length

        DEMO    10
        DEMO    100, 200

        LABEL   100
        LABEL   200

    .exit:
        %define SYS_EXIT 60
        mov     rax, SYS_EXIT
        xor     rdi, rdi
        syscall

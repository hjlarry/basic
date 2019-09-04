global main

extern printf

section .rodata
    format  db  `%lld \n`

section .text
    %macro enter 0
        push    rbp
        mov     rbp, rsp
    %endmacro

    %macro leave 0
        mov     rsp, rbp
        pop     rbp
    %endmacro

    main:
        enter
        sub     rsp, 0x10

        mov     rdi, 1
        mov     rsi, 2
        call    add

        mov     rdi, format
        mov     rsi, rax
        call    printf

        call    exit

        leave
        ret

    exit:
        mov     rax, 60
        xor     rdi, rdi
        syscall

    add:
        enter
        sub     rsp, 0x8

        add     rdi, rsi
        mov     rax, rdi
        mov     [rsp], rax

        leave
        ret
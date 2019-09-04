global main
extern printf

section .data
    s db    `hello world!\n`

section .text
    main:
        push rbp
        mov  rbp, rsp

        mov     rdi, s
        xor     rax, rax
        call    printf

        mov     rax, 0
        pop     rbx
        ret
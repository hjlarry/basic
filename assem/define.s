global _start

section .text
    %define SYS_EXIT 60
    %define MOVE(reg, val)  mov reg, val
    %define DEMO(x)         mov rax, [rbx+x]

    _start:
        MOVE(rax, 100)
        DEMO(100)

    .exit:
        mov     rax, SYS_EXIT
        xor     rdi, rdi
        syscall


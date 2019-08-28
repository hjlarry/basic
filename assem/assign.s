global _start

%assign X 100

section .text

    _start:
        mov     rax, X

        %assign X "ab"
        mov     rax, X
       
        mov     rax, 60
        xor     rdi, rdi
        syscall
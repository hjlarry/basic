global _start

section .data
    x dq 0x8070605040302010     ;dq为8个字节
    y db 1,2,3                  ;db为1个字节，这里是db*3
    leny equ $-y                ;$为当前地址，所以减去y的地址，就是y的长度

    s db "abcd", "e", "f"       ; db*6
    lens equ $-s                ; equ定义的是常量，不会存储在.data中

section .text

    _start:
        mov     rax, leny
        mov     rbx, lens
        
        mov     rax, 60
        xor     rdi, rdi
        syscall
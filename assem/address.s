global _start

section .data
    x dq 0x8070605040302010

section .text

    _start:

        xor     rax, rax    ; set $rax=0

        mov     rax, 0x55   ; 立即寻址
        mov     rbx, rax    ; 寄存器寻址
        mov     rax, [x]    ; 直接寻址

        ; 寄存器间接寻址
        mov     rcx, x
        mov     rdx, [rcx]  

        ; 寄存器相对寻址
        mov     rbx, 2
        lea     rax, [8+rbx] 

        ; 基址变址
        mov     rbx, 2
        mov     rcx, 3
        lea     rax, [rbx + rcx]           
        lea     rax, [8 + rbx + rcx]
        lea     rax, [8 + rbx + 2 * rcx]

        ; 数据复制
        mov     rax, [x]     
        sub     rax, 1
        mov     [x], rax

        ; 操作数数据长度一致。
        xor     rax, rax
        mov     eax, dword [x]


        mov     rax, 60     ; 'exit' syscall number
        xor     rdi, rdi    ;
        syscall

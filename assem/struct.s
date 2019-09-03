global _start

struc User
    .name resb 10
    .age  resq 1
endstruc


section .data
    ; u1 := User{name:"user1", age:22}
    u1 istruc User
        at User.name, db "user1"
        at User.age, dq 22
    iend

section .bss
    ; var u2 User
    u2  resb User_size

section .text
    _start:
        ; offset
        mov     rax, User       ;0
        mov     rbx, User.name  ;0
        mov     rcx, User.age   ;10
        mov     rdx, User_size  ;18
        ; address
        mov     rax, u1
        lea     rbx, [u1+User.age]  ; age_addr = u1+offset(age)

        ;u2.name = u1.name
        lea     rsi, [u1+User.name]
        lea     rdi, [u2+User.name]
        lea     rcx, [User.age - User.name]
        rep     movsb
        
        ;u2.age = u1.age
        mov     rax, [u1+User.age]
        mov     [u2+User.age], rax

    .exit:
        mov rax, 60
        xor rdi, rdi
        syscall
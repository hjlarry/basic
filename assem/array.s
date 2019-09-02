global _start

section .bss
    %assign num 10
    %assign size 8
    array resq num * size

section .text
    _start:
    ;for {
    ;    array[index] ++
    ;}
        mov rcx, num    ;array.length
        mov rax, array  ; p = &array

        xor rbx, rbx
    .loop:
        mov [rax], rbx  ;*p = rbx
        add rax, size   ; p++
        inc rbx
        loop .loop

        ; array[3] = 0x3333
        mov rbx, 3
        mov qword [array + rbx*size], 0x3333

    .exit:
        mov rax, 60
        xor rdi, rdi
        syscall
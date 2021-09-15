BITS 64

    global asm_putc

    section .text

asm_putc:

    push rbp
    mov rbp, rsp

    push rsi
    push rdx
    push rdi

    mov rax, 1
    mov rsi, rsp
    mov rdi, 1
    mov rdx, 1
    syscall

end:

    pop rdi
    pop rdx
    pop rsi

    mov rsp, rbp
    pop rbp

    ret

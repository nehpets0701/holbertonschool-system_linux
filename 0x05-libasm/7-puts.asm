BITS 64

    global asm_puts

    extern asm_strlen

    section .text

asm_puts:

    push rbp
    mov rbp, rsp

    call asm_strlen

    push rsi
    push rdx

    mov rdx, rax
    mov rax, 1
    mov rsi, rdi
    mov rdi, 1   
    syscall

end:

    pop rdx
    pop rsi

    mov rsp, rbp
    pop rbp

    ret

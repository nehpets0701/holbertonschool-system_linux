BITS 64

    global asm_memcpy

    section .text

asm_memcpy:

    push rbp
    mov rbp, rsp

    push r8b
    push r9

    mov rax, rdi

    test rdi, rdi
    jz end
    test rsi, rsi
    jz end

    xor rcx, rcx

memcpy_loop:

    cmp rcx, rdx
    jge end

    mov r8b, BYTE [rsi]
    mov BYTE [rdi], r8b

    inc rcx
    inc rsi
    inc rdi

    jmp memcpy_loop

end:

    pop r9
    pop r8

    mov rsp, rbp
    pop rbp

    ret

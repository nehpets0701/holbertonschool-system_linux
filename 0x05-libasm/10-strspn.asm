BITS 64

    global asm_strspn

    section .text

asm_strspn:

    push rbp
    mov rbp, rsp

    xor rax, rax
    xor rcx, rcx

    test rdi, rdi
    jz end
    test rsi, rsi
    jz end

strspn_loop:

    mov r8b, BYTE [rdi + rcx]
    test r8b, r8b
    jz end

    xor rdx, rdx

check_char_loop:

    mov r9b, BYTE [rsi + rdx]
    test r9b, r9b
    jz end

    cmp r8b, r9b
    je check_continue

    inc rdx
    jmp check_char_loop


check_continue:

    inc rcx
    jmp strspn_loop

end:

    mov rax, rcx

    mov rsp, rbp
    pop rbp

    ret

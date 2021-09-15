BITS 64

    global asm_strpbrk

    section .text

asm_strpbrk:

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
    jz check_continue

    cmp r8b, r9b
    je set_return

    inc rdx
    jmp check_char_loop


check_continue:

    inc rcx
    jmp strspn_loop


set_return:

    mov rax, rdi
    add rax, rcx

end:

    mov rsp, rbp
    pop rbp

    ret

BITS 64

    global asm_strncmp:

    section .text

asm_strncmp:

    push rbp
    mov rbp, rsp

    xor rcx, rcx
    xor eax, eax

loop_strcmp:

    mov r8b, BYTE [rdi + rcx]
    mov r9b, BYTE [rsi + rcx]
    inc rcx

    cmp rdx, rcx
    je end_strcmp
    test r8b, r8b
    je check_null
    ;; test r9b, r9b
    ;; je set_one
    cmp r8b, r9b
    je loop_strcmp
    jmp compare

check_null:

    test r9b, r9b
    je end_strcmp
    jmp set_negative

compare:

    cmp r8b, r9b
    jl set_negative
    jmp set_one

set_one:

    mov eax, 1
    jmp end_strcmp

set_negative:

    mov eax, -1
    jmp end_strcmp

end_strcmp:

    mov rsp, rbp
    pop rbp

    ret

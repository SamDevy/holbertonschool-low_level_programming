; This is a 64-bit assembly program that prints "Hello, World"
; to the standard output, followed by a new line.

section .data
    ; Define the message string and the newline character (ASCII 10).
    hello_message db 'Hello, World', 10
    ; Calculate the length of the message.
    message_len equ $ - hello_message

section .text
    ; Export the 'main' symbol to be visible to the linker.
    ; Using 'main' as the entry point for better compatibility with GCC.
    global main

main:
    ; Prepare for the 'write' system call.
    ; syscall number for write is 1.
    mov rax, 1
    ; File descriptor for stdout is 1.
    mov rdi, 1
    ; Pointer to the message to be written.
    mov rsi, hello_message
    ; Number of bytes to write.
    mov rdx, message_len
    ; Invoke the kernel to perform the write operation.
    syscall

    ; Prepare for the 'exit' system call.
    ; syscall number for exit is 60.
    mov rax, 60
    ; Exit code 0 indicates successful execution.
    xor rdi, rdi ; Set rdi to 0
    ; Invoke the kernel to terminate the program.
    syscall

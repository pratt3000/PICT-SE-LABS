%macro message 2
		mov rax, 01
		mov rdi, 01
		mov rsi, %1
		mov rdx, %2
		syscall
%endmacro

%macro display 2		
		mov rax, 01
		mov rdi, 01
		mov rsi, %1
		mov rdx, %2
		syscall	
%endmacro
	
copyAhead:
		mov rbx, [rax]
		add rax, 8
		add rbx, 8
		ret

arrdisplaysrc:
	mov rsi, srcblk
	mov rbx, 05
lp1:	mov rax, [rsi]
	push rsi
	push rbx
	call _printRAX
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp1
	ret
	
	
arrdisplaydst:
mov rsi, dstblk
	mov rbx, 05
lp2:	mov rax, [rsi]
	push rsi
	push rbx
	call _printRAX
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp2
	ret	



section .data
	srcblk dq 10,20, 30, 40, 50
	dstblk dq 00, 00, 00, 00, 00
	arraylen equ $ - srcblk		
	srcblkmsg: db "SRC block : "
	srcblkmsglen: equ $ -srcblkmsg
	dstblkmsg: db "DST block : "	
	dstblkmsglen: equ $ -dstblkmsg
	newline: db 10

section .text
global _start 
_start:
		mov rsi, arraylen
		message srcblkmsg, srcblkmsglen
		call arrdisplaysrc
		display newline, 1
		message dstblkmsg, dstblkmsglen
		call arrdisplaydst
		display newline, 1
		
		mov rsi, srcblk
		mov rdi, dstblk
		mov rcx, 05
nextE:	mov rax, [rsi]
		mov [rdi], rax
		add rsi, 8
		add rdi, 8  
		dec rcx
		jnz nextE

		message srcblkmsg, srcblkmsglen
		call arrdisplaysrc
		display newline, 1
		message dstblkmsg, dstblkmsglen
		call arrdisplaydst
		display newline, 1
		mov rax, 60
		mov rdi, 0
		syscall
; hex to ascii
_printRAX:
    mov rcx, digitSpace
    mov rbx, 0
    mov [rcx], rbx
    inc rcx
    mov [digitSpacePos], rcx
 
_printRAXLoop:
    mov rdx, 0
    mov rbx, 10
    div rbx
    push rax
    add rdx, 48
 
    mov rcx, [digitSpacePos]
    mov [rcx], dl
    inc rcx
    mov [digitSpacePos], rcx
   
    pop rax
    cmp rax, 0
    jne _printRAXLoop
 
_printRAXLoop2:
    mov rcx, [digitSpacePos]
 
    mov rax, 1
    mov rdi, 1
    mov rsi, rcx
    mov rdx, 1
    syscall
 
    mov rcx, [digitSpacePos]
    dec rcx
    mov [digitSpacePos], rcx
 
    cmp rcx, digitSpace
    jge _printRAXLoop2
 
    ret
section .bss
    digitSpace resb 100
    digitSpacePos resb 8	




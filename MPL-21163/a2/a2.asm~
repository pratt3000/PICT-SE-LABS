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
	display space, 1
	pop rbx
	pop rsi
	mov rax, rsi
	push rsi
	push rbx
	;display space, 1
	call _printRAX
	display space, 1
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
	display space, 1
	pop rbx
	pop rsi
	
	mov rax, rsi
	push rsi
	push rbx
	;display space, 1
	call _printRAX
	display space, 1
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp2
	ret	

arrdispovrlp:
	mov rsi, arrovrlp
	mov rbx, 10
lp3:	mov rax, [rsi]
	push rsi
	push rbx
	call _printRAX
	display space, 1
	pop rbx
	pop rsi
	
	mov rax, rsi
	push rsi
	push rbx
	;display space, 1
	call _printRAX
	display space, 1
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp3
	ret


section .data
	arrovrlp dq 10, 20, 30, 40, 50, 00, 00, 00, 00, 00
	arrovrlplen equ $ - arrovrlp
	srcblk dq 10,20, 30, 40, 50
	arraylen equ $ - srcblk	
	dstblk dq 00, 00, 00, 00, 00	
	srcblkmsg: db "SRC block : "
	srcblkmsglen: equ $ -srcblkmsg
	dstblkmsg: db "DST block : "	
	dstblkmsglen: equ $ -dstblkmsg
	srcadd: db "SRC block base address : "	
	srcaddmsglen: equ $ -srcadd
	dstadd: db "DST block base address: "	
	dstaddmsglen: equ $ -dstadd
	ovrlapmsgbf: db "Before Over lapping :"	
	ovrlapmsgbflen: equ $ -ovrlapmsgbf
	ovrlapmsgaf: db "After Over lapping :"	
	ovrlapmsgaflen: equ $ -ovrlapmsgaf
	newline: db 10
	space: db " "

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

		message srcadd, srcaddmsglen
		mov rax, srcblk		
		call _printRAX
		display newline, 1
		message dstadd, dstaddmsglen
		mov rax, dstblk
		call _printRAX
		display newline, 1
		;-------------------------------------------------
		;overlapping
		;-------------------------------------------------
		message ovrlapmsgbf, ovrlapmsgbflen
		call arrdispovrlp
		display newline, 1
		mov rsi, arrovrlp
		mov rcx, 05
		mov rdi, rsi
		add rdi, 40
nextE1:	mov rax, [rsi]
		mov [rdi], rax
		add rsi, 8
		add rdi, 8  
		dec rcx
		jnz nextE1
		
		message ovrlapmsgaf, ovrlapmsgaflen
		call arrdispovrlp
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




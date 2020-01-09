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
	display newline, 1
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
	display newline, 1
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp1
	ret


arrdisplaysrc1:
	display newline, 1
	mov rsi, srcblk1
	mov rbx, 05
lp5:	mov rax, [rsi]
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
	display newline, 1
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp5
	ret	
	
arrdisplaydst:
	display newline, 1
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
	display newline, 1
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp2
	ret


arrdisplaydst1:
	display newline, 1
	mov rsi, dstblk1
	mov rbx, 05
lp6:	mov rax, [rsi]
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
	display newline, 1
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp6
	ret	

arrdispovrlp:
	display newline, 1
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
	display newline, 1
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp3
	ret

arrdispovrlp1:
	display newline, 1
	mov rsi, arrovrlp1
	mov rbx, 10
lp4:	mov rax, [rsi]
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
	display newline, 1
	pop rbx
	pop rsi
	add rsi, 8
	dec rbx
	jnz lp4
	ret

section .data
	arrovrlp dq 10, 20, 30, 40, 50, 00, 00, 00, 00, 00
	arrovrlplen equ $ - arrovrlp
	arrovrlp1 dq 10, 20, 30, 40, 50, 00, 00, 00, 00, 00
	arrovrlplen1 equ $ - arrovrlp1
	srcblk dq 10,20, 30, 40, 50
	arraylen equ $ - srcblk	
	dstblk dq 00, 00, 00, 00, 00
	
	srcblk1 dq 10,20, 30, 40, 50
	;arraylen equ $ - srcblk1
	dstblk1 dq 00, 00, 00, 00, 00	
	
	srcblkmsg: db "SRC block (before) [non - string]: "
	srcblkmsglen: equ $ -srcblkmsg
	dstblkmsg: db "DST block (before) [non- string]: "	
	dstblkmsglen: equ $ -dstblkmsg
	srcadd: db "SRC block (after) [non - string]: "	
	srcaddmsglen: equ $ -srcadd
	dstadd: db "DST block (after) [non- string]:"	
	dstaddmsglen: equ $ -dstadd
	ovrlapmsgbf: db "Before Over lapping [non- string]:"	
	ovrlapmsgbflen: equ $ -ovrlapmsgbf
	ovrlapmsgaf: db "After Over lapping [non - string] :"	
	ovrlapmsgaflen: equ $ -ovrlapmsgaf
	ovrlapmsgbf1: db "Before Over lapping [string] :"	
	ovrlapmsgbflen1: equ $ -ovrlapmsgbf1
	ovrlapmsgaf1: db "After Over lapping [string] :"	
	ovrlapmsgaflen1: equ $ -ovrlapmsgaf1
	srcblkmsg1: db "SRC block (before) [string]: "
	srcblkmsglen1: equ $ -srcblkmsg1
	dstblkmsg1: db "DST block (before) [ string]: "	
	dstblkmsglen1: equ $ -dstblkmsg1
	srcadd1: db "SRC block (after) [string]: "	
	srcaddmsglen1: equ $ -srcadd1
	dstadd1: db "DST block (after) [string]:"	
	dstaddmsglen1: equ $ -dstadd1
	newline: db 10
	space: db " "

section .text
global _start 
_start:
		;-----------------------------------------------------------------
		;with string - non - overlapping
		;----------------------------------------------------------------
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

		message srcadd, srcaddmsglen
		call arrdisplaysrc
		display newline, 1
		message dstadd, dstaddmsglen
		call arrdisplaydst
		display newline, 1

		;-----------------------------------------------------------------
		;without string - non - overlapping
		;----------------------------------------------------------------
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
		
		;-----------------------------------------------------------------
		;with string - overlapping
		;----------------------------------------------------------------
		;over lapping 
		message ovrlapmsgbf1, ovrlapmsgbflen1
		call arrdispovrlp1
		display newline, 1
		mov rsi, arrovrlp1
		mov rdi, arrovrlp1
		add rdi, 40
		mov rcx,5
		
		cld
		rep movsq
		
		message ovrlapmsgaf1, ovrlapmsgaflen1
		call arrdispovrlp1
		display newline, 1
		
		;-----------------------------------------------------------------
		;with string - non - overlapping
		;-----------------------------------------------------------------
		message srcblkmsg1, srcblkmsglen1
		call arrdisplaysrc1
		display newline, 1
		message dstblkmsg1, dstblkmsglen1
		call arrdisplaydst1
		display newline, 1

		mov rsi, srcblk1
		mov rdi, dstblk1
		mov rcx,5	
			
		cld
		rep movsq
		
		message srcadd1, srcaddmsglen1
		call arrdisplaysrc1
		display newline, 1
		message dstadd1, dstaddmsglen1
		call arrdisplaydst1
		display newline, 1
		
		;---------------------------------------------------------------
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




%macro disp 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro accept 2
	mov rax,0
	mov rdi,0
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro
section .bss
	num resb 4
	output resb 4
	
section .data
	msg1 db 'Factorial:',10
	lenmsg1 equ $-msg1

section .text
	global _start
_start:
	disp msg1,lenmsg1
	pop rbx
	pop rbx
	pop rbx
	mov cx,0
	mov ax,01
	movzx cx,byte[rbx]
	sub cx,30h
	mov bx,cx	
	call factorial
	mov [num],rax
	call _HexToAscii
	disp output,16

;------------Exit-------------
exit:
	mov rax, 60
	mov rdi, 0
	syscall

factorial:
	cmp bx,1
	je l1
	mul bx
	dec bx
	call factorial
l1:
	ret



;------------Hex to Ascii-----------
_HexToAscii:
	mov rsi,output+15d
	mov rcx,16d
	
begin:
	xor rdx,rdx
	mov rbx,10h
	div rbx
		
	cmp dl,09h
	jbe next3
	add dl,07h
next3:
	add dl,30h
	mov byte[rsi],dl
	dec rsi
	dec rcx
	jnz begin

	ret

%macro print 2		
	mov rax, 01
	mov rdi, 01
	mov rsi, %1
	mov rdx, %2
	syscall	
%endmacro 

%macro read 2		
	mov rax, 00
	mov rdi, 00
	mov rsi, %1
	mov rdx, %2
	syscall	
%endmacro 

section .data
	dash: db "---------------------------------------"
	dash_len: equ $ -dash
	optionSet01 : 	dq "1 : Hex (4 bit) to BCD"
	optionSet01_len : 	equ $ -optionSet01
	optionSet02 : 	dq "2 : BCD (5 bit) to Hex"
	optionSet02_len : 	equ $ -optionSet02
	optionSet03 : 	dq "3 : EXIT"
	optionSet03_len :  	equ $ -optionSet03
	choice1 : 		dq "Choice : "
	choice1_len : 	equ $ -choice1
	readHex :		dq "Enter HEX (4 bit) : "
	readHex_len :	equ $ -readHex
	readBCD :		dq "Enter BCD (5 bit) : "
	readBCD_len : 	equ $ -readBCD
	newLine: dq 10
	space: dq " "

section .bss
BCD   : resb 100
hex   : resb 100
choice: resb 2
ascii : resb 100
	
section .text
global _start
_start :
	;-------------------------------------------------
	;begin
	call Menu
	read choice, 2
	cmp byte[choice], 31H
	jne Opt2_chk
	;code for hex to bcd
	call HEXtoBCD

	
	;-------------------------------------------------
Opt2_chk:	cmp byte[choice], 32H
	jne EXIT
	;code for bcd to hex
	
	
		
	;-------------------------------------------------
EXIT:	;exit call
	mov rax, 60
	mov rdi, 0
	syscall				
	;-------------------------------------------------
		
	
;-----------------------------------------------------------
;FUNCTIONS
;-----------------------------------------------------------
HEXtoBCD:
	print newLine, 1
	print readHex, readHex_len
	read ascii, 2
	print newLine, 1
	mov rax, ascii
	xor rcx, rcx
loop:	xor dx, dx
	mov dx, 10
	div dx
	push dx
	inc rcx
	cmp rax, 0
	jne loop
loop2:	pop rdx
	print rdx, 2
	dec rcx
	jnz loop2		
ret


Menu:
	print dash, dash_len
	print newLine, 1
	print optionSet01,optionSet01_len
	print newLine, 1
	print optionSet02,optionSet02_len
	print newLine, 1
	print optionSet03,optionSet03_len
	print newLine, 1
	print dash, dash_len
	print newLine, 1
	print choice1, choice1_len	
ret


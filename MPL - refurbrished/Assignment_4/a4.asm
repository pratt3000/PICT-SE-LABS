%macro print 2
	mov rax,01;
	mov rdi,01;
	mov rsi,%1;
	mov rdx,%2;
	syscall;
%endmacro	

%macro read 2
	mov rax, 00
	mov rdi, 00
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

;END MACROS-------------------------------------------------

section .data
	option1   : db "1 : Succesive Addition";
	lenoption1: equ $-option1

	option2   : db "2 : Shift Addition"
	lenoption2: equ $-option2

	option3   : db "3 : Exit"
	lenoption3: equ $-option3

	request   : db "Choice : "
	lenrequest: equ $-request

	multiplier   : db "Multiplier : "
	lenmultiplier: equ $-multiplier

	multiplicand   : db "Multiplicand : "
	lenmultiplicand: equ $-multiplicand

	answer   : db "Answer = "
	lenanswer: equ $-answer

	space: db " "

	newLine: db 10

;END .DATA--------------------------------------------------

section .bss
	inAscii  : resb 16;
	outAscii : resb 16;
	choice   : resb 1
	
;END .BSS---------------------------------------------------

section .text
global _start
_start:
	call _Menu
	read choice,2;

	cmp byte[choice],31h;
	je successiveAddition;
	
	cmp byte[choice],32h;
	je shiftAdd
	
	call _HexToAscii
	print outAscii, 15
	
exit:
	mov rax,60;
	mov rsi,00;
	syscall;	

;END .TEXT--------------------------------------------------

;FUNCTIONS--------------------------------------------------

successiveAddition:;----------------------------------------

	print multiplicand, lenmultiplicand
	read inAscii, 15
	call _AsciiToHex
	push rax				;multiplicand pushed
	print multiplier, lenmultiplier
	read inAscii, 15
	call _AsciiToHex
	push rax				; multiplier pushed
	print newLine, 1

	xor rax, rax
	pop rdi
	pop rbx

repeat:
	add rax,rbx
	dec rdi
	jnz repeat
	call _HexToAscii
	print outAscii, 16
	jmp exit
;-----------------------------------------------------------

	
shiftAdd:
	print multiplicand, lenmultiplicand
	read inAscii, 15
	call _AsciiToHex
	push rax				;multiplicand pushed
	print multiplier, lenmultiplier
	read inAscii, 15
	call _AsciiToHex
	push rax				; multiplier pushed
	print newLine, 1

	xor rax, rax
	pop rdi					;multiplicand
	pop rbx					;multiplier

notZero:
	shr rdi, 1
	jnc omit
	add rax, rbx
omit:
	shl rbx, 1
	add rdi, 0h
	jnz notZero

	call _HexToAscii
	print answer, lenanswer
	print outAscii, 16
	print newLine, 1
	jmp exit

;-----------------------------------------------------------	

_Menu:
	print newLine, 1
	print option1, lenoption1
	print newLine, 1
	print option2, lenoption2
	print newLine, 1
	print option3, lenoption3
	print newLine, 1
	print request, lenrequest
	print newLine, 1
	
ret


_AsciiToHex:					;ASCII in inAscii ----> HEX in RAX
    mov rsi,inAscii;
    xor rax,rax;
    begin1:
    cmp byte[rsi],0xA				;Compare With New Line
    je done;
    rol rax,04d;
    mov bl,byte[rsi];
    cmp bl,39h;
    jbe sub30
    sub bl,07h;
    sub30:
    sub bl,30h;
    add al,bl;
    inc rsi;
    jmp begin1;

    done:
    ret


_HexToAscii:					;HEX in RAX -----> ASCII in outAscii
    mov rsi,outAscii+15d;
    mov rcx,16d

    begin2:
    xor rdx,rdx;
    mov rbx,10h					;16d
    div rbx;

    cmp dl,09h;
    jbe add30;
    add dl,07h;
    add30:
    add dl,30h;
    mov byte[rsi],dl;

    update:
    dec rsi;
    dec rcx;
    jnz begin2;

    ret











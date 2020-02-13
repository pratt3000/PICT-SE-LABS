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

	option2   : db "2 : Booth's Multiplication"
	lenoption2: equ $-option2

	option3   : db "3 : Exit"
	lenoption3: equ $-option3

	request   : db "Choice : "
	lenrequest: equ $-request

	multiplier   : db "Multiplier : "
	lenmultiplier: equ $-multiplier

	multiplicand   : db "multiplicand : "
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
	Q0 	 	 : resb 1
;END .BSS---------------------------------------------------

section .text
global _start
_start:
	print option1, lenoption1
	call _Menu
	read choice,2;

	cmp byte[choice],31h;
	je successiveAddition;
	
	cmp byte[choice],32h;
	je boothsAlgo
	
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
	push rax												;multiplicand pushed
	print multiplier, lenmultiplier
	read inAscii, 15
	call _AsciiToHex
	push rax										    	; multiplier pushed
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

	
boothsAlgo:
	print multiplicand, lenmultiplicand
	read inAscii, 15
	call _AsciiToHex
	push rax							;multiplicand pushed
	print multiplier, lenmultiplier
	read inAscii, 15
	call _AsciiToHex
	push rax							; multiplier pushed
	print newLine, 1

	xor rax, rax	;accumulator	[A]
	pop rdi			;multiplier		[Q]
	pop rbx			;multiplicand	[B]
	mov rcx, 16d	;counter		[C]
	mov rdx, 0		;Q LSB aftr sft [Q-1]	
	bt rdi, 0		;Q0 in Q0	
	jc CY
	mov r8, 0
	jmp beginAlgo
CY:
	mov r8, 1

beginAlgo:
	xor r8, rdx		; check Q0 and Q-1
	jz SHIFT		;for 11, 00
	add rdx,0
	jz subt
	add rax, rbx
	jmp SHIFT
subt:
	sub rax, rbx
	
SHIFT:	
	shr rax, 1		;right shift [A]
	shr rdi, 1
	jc CY1
	mov rdx, 0
	jmp NCY1
CY1:
	mov rdx, 1
NCY1:
	
	
	bt rdi, 0		;Q0 in Q0	
	jc CY2
	mov r8, 0
	jmp NCY2
CY2:
	mov r8, 1
NCY2:
	dec rcx
	jnz beginAlgo	;main loop
		
	push rax
	mov rax, rdi
	call _HexToAscii
	print outAscii, 4
	print newLine, 1
	pop rax
	call _HexToAscii
	print outAscii, 4
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


_AsciiToHex:;		//ASCII in inAscii ----> HEX in RAX
    mov rsi,inAscii;
    xor rax,rax;
    begin1:
    cmp byte[rsi],0xA;	//Compare With New Line
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


_HexToAscii:;		// HEX in RAX -----> ASCII in outAscii
    mov rsi,outAscii+15d;
    mov rcx,16d

    begin2:
    xor rdx,rdx;
    mov rbx,10h;	//16d
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











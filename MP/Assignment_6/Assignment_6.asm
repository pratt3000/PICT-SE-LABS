;--------------------------------------------Messages----------------------------------------------
SECTION .data

	msg1: db "GDTR: "
	len1: equ $-msg1
	msg2: db "LDTR: "
	len2: equ $-msg2
	msg3: db "IDTR: "
	len3: equ $-msg3
	newl: db "", 10
	lenn: equ $-newl
	mswmsg db "Contents of MSW:"
	mswlen equ $-mswmsg
	
	trmsg db "Contents of TR:"
	trlen equ $-trmsg

;--------------------------------------------Variables---------------------------------------------
SECTION .bss
	cnt: resb 4
	result: resb 8
	gdtr: resw 1
		  resd 1
	ldtr: resw 1
	idtr: resw 1
		  resd 1
	tr: resw 1
	msw: resw 1
	%macro print 4
		MOV RAX, %1
		MOV RDI, %2
		MOV RSI, %3
		MOV RDX, %4
		syscall
	%endmacro
;---------------------------------------------Program----------------------------------------------
SECTION .text
global _start
_start:
	SGDT [gdtr]
	SLDT [ldtr]
	SIDT [idtr]
	STR [tr]
	SMSW word[msw]
;-----------------------------------------------GDT------------------------------------------------
	print 1, 1, msg1, len1
	MOV BX, word[gdtr+4]
	CALL HtoA
	print 1, 1, result, 4
	MOV BX, word[gdtr+2]
	CALL HtoA
	print 1, 1, result, 4
	MOV BX, word [gdtr]
	CALL HtoA
	print 1, 1, result, 4
	print 1, 1, newl, lenn
;-----------------------------------------------LDT------------------------------------------------
	print 1, 1, msg2, len2
	MOV BX, word [ldtr]
	CALL HtoA
	print 1, 1, result, 4
	print 1, 1, newl, lenn
;-----------------------------------------------IDT------------------------------------------------
	print 1, 1, msg3, len3
	MOV BX, word[idtr+4]
	CALL HtoA
	print 1, 1, result, 4
	MOV BX, word[idtr+2]
	CALL HtoA
	print 1, 1, result, 4
	MOV BX, word [idtr]
	CALL HtoA
	print 1, 1, result, 4
	print 1, 1, newl, lenn
;-----------------------------------------------MSW------------------------------------------------
	print 1,1,trmsg,trlen
	MOV BX,word[tr]
	CALL HtoA
	print 1,1,result,4
	print 1,1,newl,lenn

;-----------------------------------------------TR-------------------------------------------------
	
	print 1,1,mswmsg,mswlen
	print 1,1,newl,lenn
	MOV AX,word[msw]
	CALL HtoA
	print 1,1,result,4
	print 1,1,newl,lenn
;-----------------------------------------------exit-----------------------------------------------
	MOV RAX, 60
	MOV RDI, 0
	SYSCALL
;-----------------------------------------------HtoA-----------------------------------------------
HtoA:
	MOV RSI,result
	MOV byte[cnt], 04H		
up:	ROL BX, 04H
	MOV DL, BL
	AND DL, 0FH
	CMP DL, 09H
	JBE down
	ADD DL, 07H
down: ADD DL, 30H
	MOV byte[RSI], DL
	INC RSI
	DEC byte[cnt]
	JNZ up
	RET
;-----------------------------------------------done-----------------------------------------------


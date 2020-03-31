%macro display 2
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
	choice resb 02
	num resb 10
	digit resb 1
	one resd 1
	ten resd 1
	output resb 16

section .data
msg1 db 'Press 1: 4 Digit Hex to BCD'
l1 equ $-msg1
msg2 db 'Press 2: 5 Digit BCD to Hex'
l2 equ $ -msg2
msg3 db 'Press 3: EXIT'
l3 equ $ - msg3
msg4 db 'Enter Number:-'
l4 equ $- msg4
msg5 db 'BCD Equivalent:'
l5 equ $- msg5
msg6 db 'Hex Equivalent:'
l6 equ $- msg6
choicemsg db 'Enter Choice:-'
choicelen equ $- choicemsg 
newline db 10
newlen equ $- newline
	
section .text
global _start
_start:
	display newline,newlen
	display msg1,l1
	display newline,newlen
	display msg2,l2
	display newline,newlen
	display msg3,l3
	display newline,newlen
	display choicemsg,choicelen
	accept choice,2
	cmp byte[choice],31h
	je h2b
	cmp byte[choice],32h
	je b2h
exit:
	mov rax, 60
	mov rdi, 0
	syscall

h2b:	display newline,newlen
	display msg4,l4
	accept num,10
	call _AsciiToHex
	xor rdx,rdx
	mov rbx,10d
	push rbx
	label:
	    div rbx;
            push rdx;
            xor rdx,rdx;
            add rax,0h;
            jnz label;
	disp:
		xor rbx,rbx
		pop rbx
		cmp rbx,10d
		 je _start
		add rbx,30h
		mov [digit],rbx
		display digit,1
		jmp disp	
b2h:
	display newline,newlen
	display msg4,l4
	accept num,10
	call _AsciiToHex
	mov qword[one],1d
	mov byte[ten],10d
	mov rbx,10h
	xor rcx,rcx

multiply:
	xor rdx,rdx
	div rbx
	push rax
	
	mov rax,rdx
	mul dword[one]
	add rcx,rax
	xor rax,rax
	mov eax,dword[one]	
	mul dword[ten]
	mov dword[one],eax
	
	pop rax
	add rax,0h
	jnz multiply
	
	mov rax,rcx
	call _HexToAscii
	display msg6,l6
	display output,16
	display newline,newlen
	jmp _start

_AsciiToHex:;		
    mov rsi,num;
    xor rax,rax;
    begin1:
    cmp byte[rsi],0xA;	
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

_HexToAscii:
	mov rsi,output+15d
	mov rcx,16d
	
begin:
	xor rdx,rdx
	mov rbx,10h
	div rbx
		
	cmp dl,09h
	jbe next1
	add dl,07h
next1:
	add dl,30h
	mov byte[rsi],dl
	dec rsi
	dec rcx
	jnz begin

	ret

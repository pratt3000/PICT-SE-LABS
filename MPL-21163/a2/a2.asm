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
	
%macro copyAhead 2
		mov rbx, [rax]
		add rax, 8
		add rbx, 8
%endmacro

section .data
	srcblk dq 10h,20h, 30h, 40h, 50h
	dstblk dq 00h, 00h, 00h, 00h, 00h
	arraylen equ $ - srcblk		
	srcblkmsg: db "SRC block : "
	dstblkmsg: db "DST block : "
	srcblkmsglen: equ $ -srcblkmsg
	dstblkmsglen: equ $ -dstblkmsg

section .text
global _start 
_start:
		mov rsi,05h
		message srcblkmsg, srcblkmsglen
		display srcblk, 05
		newline: db 10
		message dstblkmsg, dstblkmsglen
		display dstblk, 05
		newline: db 10
		mov rax, srcblk
		mov rbx, dstblk
nextE:	copyAhead rax, rbx
		dec rsi
		jz nextE
		message srcblkmsg, srcblkmsglen
		display srcblk, 05
		message dstblkmsg, dstblkmsglen
		display dstblk, 05






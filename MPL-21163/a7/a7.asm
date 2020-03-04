%include "macro.asm"

section .data

	message 		: db "~Sorting completed"
	lenMessage 		: equ $-message

	reqFile			: db "File Name: "
    lenReqFile		: equ $-reqFile

	space 			: db " "
	newline  		: db 10d

	errMsg			: db "Error!"
    lenErrMsg		: equ $-errMsg

section .bss
	fileName 		: resb 64
	buffer 			: resb 8192
	lenbuffer 		: equ $-buffer
	fileDescriptor	: resq 1
	lenText			: resq 1
	array 			: resb 20

section .text
	global _start
	_start :       
	
	print reqFile,lenReqFile
    read fileName,64

	dec rax							;extra bit gets added
	mov byte[fileName+rax], 0		;0 is appended for EOF

	fopen fileName
	cmp rax, -1d
	jle error						;for file DNE
	mov [fileDescriptor],rax		;fileName is stored 

	fread [fileDescriptor], buffer, lenbuffer
	mov [lenText], rax				;file content length
	
	call processBuffer
	call bubbleSort
	call processArray

	print buffer,[lenText]
	fwrite [fileDescriptor],buffer,[lenText];
	jmp exit
									
	error:
	print errMsg, lenErrMsg

	exit:
	fclose [fileDescriptor]
	mov rax, 60
	mov rdi, 0
	syscall

processBuffer:
	mov rcx, [lenText]
	mov rsi, buffer
	mov rdi, array
	
	start0:;      <<-------\
	
	mov al, [rsi];			|
	mov [rdi], al;			|
;							|
	update0:;				|
	inc rsi;				|			
	inc rdi;				|
	dec rcx;				|
	jnz start0;    --------/
ret

bubbleSort:
	mov rsi, 0h								;i = 0
	mov rcx, [lenText]
	dec rcx

	outerLoop:
		mov rdi, 0h							;j = 0
		innerLoop:
			mov rax, rdi					;j
			inc rax							;j+1
			mov bl, byte[array + rdi]		;array[j]
			mov dl, byte[array + rax]		;array[j+1]
			cmp bl, dl						;main compare
			jnc skip0
			mov byte[array + rdi], dl		;swap
			mov byte[array + rax], bl		;swap
			skip0:
			inc rdi
			cmp rdi, rcx
			jb innerLoop
		inc rsi
		cmp rsi, rcx
		jb outerLoop
ret

processArray:
	mov rsi,array;
	mov rdi,buffer;
	mov rcx,[lenText];
	
	begin1:
	mov al,[rsi];
	mov [rdi],al;
	
	update1:
	inc	rsi;
	inc rdi;
	dec rcx;
	jnz begin1
ret




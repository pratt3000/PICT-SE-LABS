section .data
arr dw 1,2,-3,4,-5
count1 db 0
count2 db 0

section .text
global _start   
	
_start:	mov esi, arr
		mov ecx, 5 			;no of elements
		mov ebx, 0			;+ve number count
		mov edx, 0
		
loop1:	
		mov eax, [esi]
		add eax, 0				;rotate left through carry
		js pos1				;jump if -ve
		inc ebx				;-ve count
		jmp update		

pos1:		inc edx
	
update:
		add esi, 4		
		dec ecx				;iteration
		jnz loop1				;on complete ignore
	
done: 
		add   ebx, 30h
		add   edx, 30h			;ascii value
		mov  [count1], ebx		;assign
		mov [count2], edx		

display:

		mov  edx,1    			;message length
		mov  ecx, count1 		;message to write
		mov  ebx, 1     			;file descriptor (stdout)
		mov  eax, 4     			;system call number (sys_write)
		int  80H      			;call kernel
		
		mov  edx,1    			;message length
		mov  ecx, count2 		;message to write
		mov  ebx, 1     			;file descriptor (stdout)
		mov  eax, 4     			;system call number (sys_write)
		int  80H
		

		mov  eax, 1     			;system call number (sys_exit)
		int  80H      			;call kernel	



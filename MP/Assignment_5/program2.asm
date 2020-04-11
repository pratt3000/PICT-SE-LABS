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


extern file_descriptor,buffer,len_file
global _spaceCount,_lineCount,_charCount

section .bss
blank resb 2
line resb 2
charcount resb 2
char1 resb 2
output resb 4

section .data
msg db 'Enter character to be counted:'
l equ $-msg

section .text
 
 _spaceCount:
        
	mov r10,[len_file]           ;move length of file to r10 register
        mov rsi,buffer               ;move buffer to rsi
    a1:	
        cmp byte[rsi],20h            ;compare rsi with ascii value of space
	je aa1                       ;jump to aa1 if equal
	jmp k                        ;else jump to k

  aa1:  inc byte[blank]              ;increment blank
  k:	inc rsi                      ;increment rsi
	dec r10                      ;decrement r10
	jnz a1                       ;loop a1
	cmp byte[blank],9           ;compare with 9
	jbe b1                       ;jump to b1 if below or equal
	add byte[blank],7h           ;add 7h to convert to ascii
b1:	add byte[blank],30h          ;convert to ascii
	display blank,2              ;display count of blank spaces
         ret


_lineCount:
        mov r10,[len_file]           ;move length of file to r10 register
        mov rsi,buffer               ;move buffer to rsi
    a2:	
        cmp byte[rsi],10d            ;compare rsi with ascii value of newline
	je aa2                       ;jump to aa2 if equal
	jmp l2                       ;else jump to l2

  aa2:  inc byte[line]               ;increment blank
  l2:	inc rsi                      ;increment rsi
	dec r10                      ;decrement r10
	jnz a2                       ;loop a2
	cmp byte[line],9           ;compare with 9
	jbe b2                       ;jump to b2 if below or equal
	add byte[line],7h            ;add 7h
b2:	add byte[line],30h	     ;add 30h to convert to ascii
	display line,2               ;display count of lines
         ret

_charCount:
	display msg,l                ;display msg to accept character
        accept char1,2               ;accept character
	mov r10,[len_file]           ;move length of file to r10
	mov dl,byte[char1]           ;move contents of char1 to rdx
	mov rsi,buffer               ;make rsi point to buffer
   a3:  cmp byte[rsi],dl             ;compare contents at rsi to rdx
 	je aa3                       ;jump to aa3 if equal
	jmp l3
 aa3:   inc byte[charcount]          ;increment charcount
 l3:    inc rsi                      ;increment rsi
	dec r10                      ;decrement r10
	jnz a3                       ;loop a3
	cmp byte[charcount],9       ;compare with 9
	jbe b3                       ;jump to b1 if below or equal
	add byte[charcount],7h       ;add 7h to convert to ascii
b3:	add byte[charcount],30h      ;convert to ascii
	display charcount,2          ;display count of blank spaces
         ret
 exit:  mov rax,60
	mov rdi,0
	syscall

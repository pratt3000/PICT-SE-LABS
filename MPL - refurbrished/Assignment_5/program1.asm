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


global character,line,file_descriptor,buffer,len_file
extern _spaceCount,_lineCount,_charCount


section .bss
 choice resb 2
 file_descriptor resq 1
 buffer resb 100
 len_buffer equ $-buffer

len_file resb 2

section .data
 msg1 db 'Enter 1.Count blank spaces'
 l1 equ $-msg1
 msg2 db '2.Count new line'
 l2 equ $-msg2
 msg3 db '3.Count occurences of'
 l3 equ $-msg3
 msg4 db '0.Exit'
 l4 equ $-msg4
 newline db '',0xa
 ln equ $-newline
 filename dw 'file1.txt',0
 msg5 db 'Count is:'
 l5 equ $-msg5


section .text
 global _start
_start:

        ;Opening the file
	mov rax,2                     ;'open' syscall
	mov rdi,filename              ;file name
	mov rsi,2                     ;File access mode
	mov rdx,0777                  ;permission set
	syscall
	
	mov [file_descriptor],rax     ;file descriptor  

        ;Reading from file
	
	mov rax,0                     ;'read' syscall
	mov rdi,[file_descriptor]     ;file pointer
	mov rsi,buffer                ;buffer for read
	mov rdx,len_buffer            ;length of data to be read
	syscall
        
        mov [len_file],rax            ;move length of file to len_file
	
        display newline,ln
	display msg1,l1               ;Display choice 1.Count blank spaces
	display newline,ln
	display msg2,l2               ;Display choice 2.Count new line
	display newline,ln
	display msg3,l3               ;Display choice 3.Count occurences of
	display newline,ln
	display msg4,l4               ;Display choice 0.Exit
       
	accept choice,2               ;accept choice
	
	cmp byte[choice],49           ;compare choice with ascii value of 1
	je label1                     ;go to label1 if zero flag set
	cmp byte[choice],50           ;compare choice with ascii value of 2
	je label2                     ;jump to label2 if zero flag set
	cmp byte[choice],51           ;compare choice with ascii value of 3
	je label3                     ;jump to label3 if zero flag set
	jmp exit                      ;jump to exit

label1:display msg5,l5                ;message of displaying count
       call _spaceCount
	jmp _start
	
label2:display msg5,l5
	call _lineCount
	jmp _start
label3:display msg5,l5
	call _charCount
	jmp _start
 exit:  mov rax,60
	mov rdi,0
	syscall


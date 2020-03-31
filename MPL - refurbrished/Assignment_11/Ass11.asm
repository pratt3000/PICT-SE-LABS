
%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data
meanmsg db "Calculated Mean is:"
meanlen equ $-meanmsg
sdmsg db "Standard is:"
sdlen equ $-sdmsg
varmsg db "Variance is:"
varlen equ $-varmsg
array dd 30.43,56.29,32.93,94.28,22.46
arraycount dw 05
dpoint db '.'
hdec dq 100
newline db "",10

section .bss
dispbuff resb 1
resbuff rest 1
mean resd 1
variance resd 1

section .text
global _start
_start:

finit 
fldz
mov rbx,array
mov rsi,00
xor rcx,rcx
mov cx,[arraycount]

up:
fadd dword[rbx+rsi*4]
inc rsi
loop up

fidiv word[arraycount]
fst dword[mean]
print meanmsg,meanlen
call dispres

xor rcx,rcx
mov cx,[arraycount]
mov rbx,array
mov rsi,00
fldz

up1:
fld dword[array+rsi*4]
fsub dword[mean]
fmul st0
fadd
inc rsi
loop up1

fidiv word[arraycount]
fst dword[variance]
fsqrt
print newline,1
print sdmsg,sdlen
call dispres

fld dword[variance]
print newline,1
print varmsg,varlen
call dispres
print newline,1
exit:
mov rax,60
mov rdi,0
syscall

disp8_proc:
mov rdi,dispbuff
mov rcx,02
back:
rol bl,04
mov dl,bl
and dl,0FH
cmp dl,09H
jbe next1
add dl,07H
next1:
add dl,30H
mov [rdi],dl
inc rdi
loop back

ret

dispres:
fimul dword[hdec]
fbstp tword[resbuff]
xor rcx,rcx
mov rcx,09H
mov rsi,resbuff+9

up2:
push rcx
push rsi
mov bl,[rsi]
call disp8_proc
print dispbuff,2
pop rsi
dec rsi
pop rcx
loop up2
print dpoint,1
mov bl,[resbuff]
call disp8_proc
print dispbuff,2
ret

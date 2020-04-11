global main
extern printf,scanf

%macro myprintf 3
pop qword[stack];
mov rdi,%1;
movsd xmm0,qword[%2];		//MOVSD — Move Scalar Double-Precision Floating-Point Value
movsd xmm1,qword[%3];
mov rax,2;
call printf
push qword[stack];
%endmacro

%macro print 2
mov rax,1;
mov rdi,1;
mov rsi,%1;
mov rdx,%2;
syscall
%endmacro

%macro myscanf 1
pop qword[stack];
mov rdi,readFormat;
mov rsi,rsp;
call scanf;
mov rax,qword[rsp];
mov qword[%1],rax;
push qword[stack];
%endmacro

section .data
eqn: db "Ax^2 + Bx + C = 0",10;
lenEqn: equ $-eqn;

reqA: db "Coefficient of x^2 (A): ";
lenReqA: equ $-reqA;

reqB: db "Coefficient of x (B): ";
lenReqB: equ $-reqB;

reqC: db "Constant (C): ";
lenReqC: equ $-reqC;
newline db " ",10
rootsMsg: db "Roots:",10;
lenRootsMsg: equ $-rootsMsg;
ff1: db "%lf +i %lf",10,0
ff2: db "%lf -i %lf",10,0
readFormat: db "%lf",0;
four: dq 4
two: dq 2
zero: dq 0
ipart1: db "+i",10
ipart2: db "-i",10


section .bss
a resq 1
b resq 1
c resq 1
b2 resq 1
fac resq 1
delta resq 1
rdelta resq 1
r1 resq 1
r2 resq 1
ta resq 1
real resq 1
img resq 1
stack resq 1

section .text
main:
print reqA,lenReqA
myscanf a

print newline,1
print reqB,lenReqB
myscanf b

print newline,1
print reqC,lenReqC
myscanf c

;myprintf a
;myprintf b
;myprintf c

fld qword[b]
fmul qword[b]
fstp qword[b2]

fild qword[four]
fmul qword[a]
fmul qword[c]
fstp qword[fac]

fld qword[b2]
fsub qword[fac]
fstp qword[delta]

fild qword[two]
fmul qword[a]
fstp qword[ta]

btr qword[delta],63
jc imaginary


fld qword[delta]
fsqrt
fstp qword[rdelta]

fldz 
fsub qword[b]
fadd qword[rdelta]
fdiv qword[ta]
fstp qword[r1]
print newline,1
print rootsMsg,lenRootsMsg
myprintf ff1,r1,zero

fldz 
fsub qword[b]
fsub qword[rdelta]
fdiv qword[ta]
fstp qword[r2]
myprintf ff2,r2,zero

jmp exit


imaginary:
fld qword[delta]
fsqrt
fstp qword[rdelta]

fldz 
fsub qword[b]
fdiv qword[ta]
fstp qword[real]

fld qword[rdelta]
fdiv qword[ta]
fstp qword[img]

print newline,1;
print rootsMsg,lenRootsMsg;
myprintf ff1,real,img
myprintf ff2,real,img

exit:
mov rax,60
mov rdi,0
syscall


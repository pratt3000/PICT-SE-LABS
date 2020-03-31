.model tiny

.code

ORG 0100h
start:

	jmp trans
	
	intvect dd?
	temp db 00h
	hr db ?
	min db ?
	sec db ?
resi:
	push ax
	push bx
	push cx 
	push dx
	
	push si
	push di
	push sp
	push bp
	
	push ss
	push es
	push ds
	
	mov ah,02h
	int 1Ah
	
	mov cs:hr,ch
	mov cs:min,cl
	mov cs:sec,dh

	inc cs:temp

	mov ax,0B800h
	mov es,ax
	mov di,0100

	mov al,cs:hr
	and al,0F0h
	mov cl,04
	shr al,cl
	add al,30h
	mov es:[di],al
	inc di
	inc di

	mov al,cs:hr
	and al,0Fh
	add al,30h
	mov es:[di],al
	inc di
	inc di

	mov al,':'
	mov es:[di],al
	inc di
	inc di

	mov al,cs:min
	and al,0F0h
 	mov cl,04h
	shr al,cl
	add al,30h
	mov es:[di],al
	inc di
	inc di
	
	mov al,cs:min
	and al,0Fh
	add al,30h
	mov es:[di],al
	inc di
	inc di

	mov al,':'
	mov es:[di],al
	inc di
	inc di

	mov al,cs:sec
	and al,0F0h
	mov cl,04h
	shr al,cl
	add al,30h
	mov es:[di],al
	inc di
	inc di

	mov al,cs:sec
	and al,0Fh
	add al,30h
	mov es:[di],al
	inc di
	inc di

	cmp cs:temp,60
	jne nobeep
		
	mov cs:temp,00h

	mov al,128
	out 43h,al
	mov ax,8126
	
	out 42h,al
	mov al,ah
	out 42h,al
	in al,61h
	
	or al,00000011b
	out 61h,al
	mov bx,100

pause1:
	mov cx,9999
pause2:
	dec cx
	jnz pause2
	dec bx 
	jnz pause1
	in al,61h

	and al,11111100b
	out 61h,al

nobeep:
	pop es
	pop ds
	pop ss

	pop bp
	pop sp
	pop di
	pop si
	
	pop dx
	pop cx
	pop bx
	pop ax

	jmp dword ptr cs:intvect

trans:
	cli
	mov ah,35h
	mov al,08h
	int 21h
	
	mov word ptr intvect,bx
	mov word ptr intvect+2,es

	mov ah,25h
	mov al,08h
	mov dx,offset resi
	int 21h

	mov ah,31h
	mov al,00h
	mov dx,offset trans
	sti
	int 21h

end start
	 

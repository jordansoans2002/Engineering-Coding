.8086
.model small

.data
	num1 dw 119eH
	num2 dw 119eh
	sum dw ?
	carry db ?

.code
	start:mov ax,@data
	mov ds,ax
	lea si,num1
	mov cx,0000h
	mov ax,[si]
	mov bx,[si+1]
	add ax,bx
	jnc noCarry
	mov cl,01h
	noCarry: mov carry,cl
	mov sum,ax
	mov ah,4ch
	int 21h
end start
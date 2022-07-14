.8086
.model small

.data
	num1 db 9eH
	num2 db 9eh
	sum db ?
	carry db ?

.code
	start:mov ax,@data
	mov ds,ax
	lea si,num1
	mov cx,0000h
	mov bl,[si]
	mov bh,[si+1]
	add bl,bh
	jnc noCarry
	mov cl,01h
	noCarry: mov carry,cl
	mov sum,bl
	mov ah,4ch
	int 21h
end start

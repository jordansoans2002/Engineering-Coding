.8086
.model small

.data
	A db 22h
	b db 44h
	p dw ?

.code
	start: mov ax,@data
	mov  ds,ax
	lea si, A
	mov al,[si]
	mov dl,[si+1]
	imul dl
	mov p,ax
	mov ah,4cH
	int 21H
end start
		


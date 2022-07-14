.8086
.model small

.data
	s db 1,3,5,7,2

.code
	start:
	mov ax,@data
	mov ds,ax
	
	mov cl,05
	lea si,s
	
	chk:cmp ah,[si]
	jnc incr
	mov ah,[si]
	incr:inc si
	loop chk
	int 03
end start
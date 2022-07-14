.8086
.model small

.data
	src db 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1
	dst db ?

.code
	start:mov ax,@data
	mov ds,ax
	mov es,ax
	mov cx,15

	lea si,src
	lea di,dst

	cld
	rep movsb
	
	INT 03
end
	
.8086
.model small

;.data
;	s db 1H
;	s1 db 2H
;	s2 db 3H

.code
	start:
	mov ax,0000H
	mov ds,ax
	mov es,ax

	mov si,0005 ;source string
	mov di,000CH ;destination
	mov cx,0002H ;len

	cld
	rep movsb
	
	mov ah,4CH
	int 21H
end start

	
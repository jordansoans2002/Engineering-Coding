.8086
.model small

.data
 A dw 0111H
 B dw 0022H
 p dd ?

.code
 start: mov ax,@data
 mov ds,ax
 lea si,A
 mov ax,[si]
 mov dx,[si+2]
 imul dx
; mov p,ax
 
 mov ah,4cH
 int 21H
end start
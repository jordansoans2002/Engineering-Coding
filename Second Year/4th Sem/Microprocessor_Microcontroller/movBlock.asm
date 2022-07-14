.8086
.model small

.data
s1 db 1,2,3,4,5
s2 db ?

.code
        start:
        mov ax,@data
        mov ds,ax
        mov es,ax
        lea si,s1 ;offset of source string
        lea di,s2 ;offset of destination string
        mov cx,05H ;length of string

        cld
        rep movsb

        mov ah,4CH
        int 03H
end start

	

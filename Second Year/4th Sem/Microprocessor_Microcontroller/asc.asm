.8086
.model small

.data
s1 db 5,4,3,2,1

.code
        start:
        mov ax,@data
        mov ds,ax
        lea si,s1
        mov ch,04

        setInt:mov cl,04
        lea si,s1

        chk:mov al,[si]
        mov ah,[si+1]
        cmp al,ah
        jc up

        mov [si+1],al
        mov [si],ah

        up:
        inc si
        dec cl
        jnz chk

        dec ch
        jnz setInt

        exit:
        int 03
end start

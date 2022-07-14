.8086
.model small

.data
	A dd 45321309H
	B dd 37221382H
	p dq ?

.code
	start: mov ax,@data
	mov ds,ax
	lea si,A
	lea di,p

;s0=lsb1 s2=msb1 s4=lsb2 s6=msb2
	mov ax,[si]
	mov dx,[si+4]
	mul dx
	mov [di],ax ;lsb 1908
	mov [di+2],dx ;lsb1*lsb2 091A
	
	mov ax,[si]
	mov dx,[si+6]
	mul dx
	add [di+2],ax ;lsb 92C6
	mov [di+4],dx ;lsb1*msb2 06D3
	
	mov ax,[si+2]
	mov dx,[si+4]
	mul dx
	add [di+2],ax ;lsb 0C84
	adc [di+4],dx ;msb1*lsb2 048D
	
	mov ax,[si+2]
	mov dx,[si+6]
	mul dx
	adc [di+4],ax ;lsb C963
	mov [di+6],dx ;msb1*msb2 0369
	int 03H
end start


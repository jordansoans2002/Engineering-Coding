;to initialize the keypad
org 500H
   	table: db 'e','x','p','e','r','i','m','e','n','t',' ',7
	;table: db 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
	mov dptr,#500H


org 0000
	mov A,#38H ;init 2 lines of 5x7
	acall cmd
	mov a,#0EH ;disp on cursor on
	acall cmd
	mov A,#01H ;clr
	acall cmd
   	 
    mov a,#06H ;shift cursor right
	acall cmd
	mov A,#80H ;move cursor to line 1 pos 0(80)+0=80
	acall cmd
	mov a,#'s'
	acall dwrt
	mov a,#'e'
	acall dwrt
	mov a,#'t'
	acall dwrt
	sjmp kp_row
    
	cmd:acall delay
    mov P3,A
	clr P2.0
	clr P2.1
	setb P2.2
    acall delay
	clr P2.2
	acall delay
    ret
    
	dwrt:acall delay
    mov P3,A
	setb P2.0
	clr P2.1
	setb P2.2
    acall delay
	clr P2.2
	acall delay
    ret
    
	delay:mov R3,#60H
	here2:mov R4,#0FFH
	here:djnz R4,here
	djnz R3,here2
	ret
    
    
	kp_row:mov P1,#0FH
    mov A,P1
	mov P0,P1
    cjne A,#0FH,calc1
    sjmp kp_row

    calc1:;mov P0,A
	LCALL get_pos
    mov B,#04
    mul AB
    mov R0,A

    mov P1,#0F0H
    mov A,P1
    cjne A,#0F0H,calc2

    calc2:LCALL get_pos
    add A,R0
    movc A,@A+DPTR
	acall dwrt
	sjmp kp_row

    get_pos:mov R1,#00
    rep:rrc A
    JNC stop
    inc R1
    sjmp rep
    stop:mov A,R1
    ret
end
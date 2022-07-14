org 400H
	table: db 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
	mov dptr,#0400H

org 0000H
    kp_row:mov P1,#0FH
    mov A,P1
    cjne A,#0FH,calc1
    sjmp kp_row

    calc1:LCALL get_pos
    mov B,#04
    mul AB
    mov R0,A

    mov P1,#0F0H
    mov A,P1
    cjne A,#0F0H,calc2

    calc2:LCALL get_pos
    add A,R0
    movc A,@A+DPTR
    mov P3,A
    sjmp kp_row

    get_pos:mov R1,#00
    rep:rrc A
    JNC stop
    inc R1
    sjmp rep
    stop:mov A,R1
    ret
end

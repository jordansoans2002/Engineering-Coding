org 0000H
	mov A,#38H ;init 2 lines of 5x7
	acall cmd
	;acall delay
	mov a,#0EH ;disp on cursor on
	acall cmd
	;acall delay
	mov A,#01H ;clr
	acall cmd
	;acall delay
   	 
    mov a,#06H ;shift cursor right
	acall cmd
	;acall delay
	mov A,#84H ;move cursor to line 1 pos 0(80)+4=84
	acall cmd
    ;acall delay
	mov a,#'E'
	acall dwrt
	;acall delay
	mov a,#'x'
	acall dwrt
	;acall delay
	mov a,#'p'
	acall dwrt
	;acall delay
	mov a,#'t'
	acall dwrt
	;acall delay
	mov a,#' '
	acall dwrt
	;acall delay
	mov a,#'9'
	acall dwrt
	;acall delay
    stop:sjmp stop
    
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
end
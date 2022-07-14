org 0000H
	mov A,#38H ;init 2 lines of 5x7
	acall cmd
	mov a,#0EH ;disp on cursor on
	acall cmd
	mov A,#01H ;clr
	acall cmd
   	 
    	mov a,#06H ;shift cursor right
	acall cmd
	mov A,#84H ;move cursor to line 1 pos 0(80)+4=84
	acall cmd
	mov a,#'E'
	acall dwrt
	mov a,#'x'
	acall dwrt
	mov a,#'p'
	acall dwrt
	mov a,#'t'
	acall dwrt
	mov a,#' '
	acall dwrt
	mov a,#'9'
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

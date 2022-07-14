org 0000H
	mov A,#01H
	rot:rl A
	mov P2,A
	acall delay
	cjne A,#08H,rot
	mov A,#01H
	sjmp rot
	
	delay:mov R1,#90H
	l1:mov R2,#0FFH
	l2:djnz R2,l2
	djnz R1,l1
	ret
end	
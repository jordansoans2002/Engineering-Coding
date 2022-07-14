org 0000
	setb P3.2
	repeat: jb P3.2,l1
	mov P1,#0FH
	sjmp repeat
	l1:mov P1,#0F0H
	sjmp repeat
end
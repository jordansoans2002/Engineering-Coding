org 0000H
  mov R0, #20H
  mov A, #0
  
  chk:mov B, @R0
  cjne A,B,l1
  l1:jnc incr
  mov A,B
  
  incr: inc R0
  chne R0,#2Ah,l2
  sjmp stop
  l2:jc chk
  stop:mov R3,A
end

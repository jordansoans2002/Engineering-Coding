org 0000H
  mov R0, #20H
  mov A, #01H
  mov @R0, #00H
  inc R0
  
  print:mov @R0,A
  add A,B
  mov B,@R0
  inc R0
  cjne R0,#2AH,print
end

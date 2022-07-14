org 0000H
  setb P3.2
  rep:jb P3.2,l1
  mov P1,#0FH
  sjmp rep
  l1:mov P1,#0F0H
  sjmp rep
end

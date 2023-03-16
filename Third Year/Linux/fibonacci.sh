#!/bin/bash
echo "Enter max value of fibonacci series"
read n
a=0
b=1
c=1 
while [ $b -lt $n ]
do
	c=$(($a+$b))
	a=$b
	b=$c
done
echo $a
chmod u+x ${0##*/}	

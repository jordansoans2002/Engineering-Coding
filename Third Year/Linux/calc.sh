#!/bin/bash
echo "enter first number"
read a
echo "enter second number"
read b
echo "enter 1.add 2.subtract 3.multiply 4.divide"
read c
case $c in 1) echo $(($a + $b));;
2) echo $(($a - $b));;
3) echo $(($a * $b));;
4) echo $(($a / $b));;
*) echo "invalid option";;
esac
chmod u+x ${0##*/}

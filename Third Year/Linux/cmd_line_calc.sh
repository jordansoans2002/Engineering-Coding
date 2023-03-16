#!/bin/bash
if [ $# -lt 3 ] 
then echo "give two operands and one operation"
else
	case $2 in "+") echo $(($1 + $3));;
	"-") echo $(($1 - $3));;
	"*") echo $(($1 * $3));;
	"/") echo $(($1 / $3));;
	*) echo "invalid option";;
	esac
fi
chmod u+x ${0##*/}

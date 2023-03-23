#!/bin/bash
if [ $# -lt 3 ]
then
	echo "To execute you have to enter 3 arguments in following order..."
	echo "File name, starting line and ending line.."
else
	sed -n $2,$3p $1
fi

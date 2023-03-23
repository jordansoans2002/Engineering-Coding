#!/bin/bash
if [ $# -lt 1 ]
then
	echo "Enter file to check"
else
	sed '2d;10d' $1
fi

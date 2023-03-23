#!/bin/bash
if [ $# -ne 1 ] 
then
	echo "Give the file as arguement"
else
	wc -m $1
fi

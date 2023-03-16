#!/bin/bash
read a
read b
read c
if [[ "$a" == "$b" && "$b" == "$c" ]];
then echo "equilateral"
fi
chmod u+x ${0##*/}

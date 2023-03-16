#!/bin/bash
if [ $# -lt 1 ] 
then echo "Give file as parameter"
else
sed '/^$/d' $1
fi
chmod u+x ${0##*/}

#!/bin/bash
if [ $# -lt 2 ] 
then echo "Enter directory whose files should be formatted and prefix"
else
files=`ls $1`
for file in $files
do
	mv $1/$file "$1/$2""$file"
done
fi
chmod u+x ${0##*/}

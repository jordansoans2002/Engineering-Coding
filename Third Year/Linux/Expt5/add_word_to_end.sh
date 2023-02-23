#!/bin/bash
if [ $# -lt 2 ]
then 
  echo "Give file name and word as parameters"
else
  sed -i s/$/$2/ $1
  cat $1
fi

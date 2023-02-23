#!/bin/bash
if [ $# -lt 1 ]
then
  echo "Add file name as parameter"
 else
  sed '2d,10d' $1
fi

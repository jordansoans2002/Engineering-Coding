#!/bin/sh
args="$@"

print(){
  if [ $n -gt 0 ]
  then echo "${args[$n]}"
  n=$((n-1))
  print n
  fi
}
print $#
chmod u+x ${0##*/}

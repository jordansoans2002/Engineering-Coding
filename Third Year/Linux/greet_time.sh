#!/bin/bash
greet='Good '
time=`date +%R`
hour="$time"| cut -c 1-2
echo $time $hour
if [ $hour -gt 5 -a $hour -lt 12 ]
  then greet="Good morning"
elif [ $hour -gt 12 -a $hour -lt 1 ]
  then greet="Good noon"
elif [ $hour -gt 2 -a $hour -lt 5 ]
  then greet="Good afternoon"
elif [ $hour -gt 5 -a $hour -lt 9 ]
  then greet="Good evening"
elif [ $hour -gt 9 -a $hour -lt 5 ]
  then greet="Good night"
fi
echo $greet user, Have a nice day !
echo "It's `date`"
chmod u+x ${0##*/}

#!/bin/bash
echo $PATH
ls -l $PATH|grep 'rwxrwxrwx'| wc -l
chmod u+x ${0##*/}

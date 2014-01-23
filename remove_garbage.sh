#!/bin/bash
#This script help reomve garbage file like a.out, *.o, and executables


for dirpath in "2014_-_寒訓" "NTHU_OJ_code"
do
    cd ${dirpath}/
    #Replace space with '_' first
    find -name "* *" -type f | rename 's/ /_/g'

    rm a.out
    rm *.o
    ls | grep -v "\." | xargs rm
    
    echo "${dirpath} done"
    cd ..
done

echo 'done'
exit 0

#!/bin/sh

#remove .o, a.out, executables
sh remove_garbage.sh
echo 'remove garbage done'

#git add all 
git add .
#git commit

read -p "Please enter your comment:" commit
git commit -m $commit
git push

echo 'git push done'
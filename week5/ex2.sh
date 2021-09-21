#!/bin/bash 
filename='ex2.txt'
check_file='file.lock'
n=1

while true
do
  if [ ! -f $check_file ]; then
    touch $check_file
    while read line; do
    n=$((n+1))
    done < $filename
    rm $check_file
    echo $n >> $filename
  fi
done
exit 0;

# Explanations:
# To prevent such a race between two processes, it is necessary to use file.lock. 
# Here, the algorithm, when it accesses a buffer, it creates a file.lock, which indicates that 
# a process is working with buffer at that moment.
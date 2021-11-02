#!/bin/bash
touch ex2.c
touch file1
touch file2
gcc ex2.c -o ex2.out
./ex2.out > ex2.txt
mkdir ./lib
mkdir ./lib/x86_65-linux-gnu
sudo libs=($(ldd /bin/echo | awk '{print $3}')); for i in $libs; do cp $i lofsdisk$(echo $i | sed 's/\/usr//'); done
sudo libs=($(ldd /bin/ls | awk '{print $3}')); for i in $libs; do cp $i lofsdisk$(echo $i | sed 's/\/usr//'); done
sudo libs=($(ldd /bin/bash | awk '{print $3}')); for i in $libs; do cp $i lofsdisk$(echo $i | sed 's/\/usr//'); done
sudo libs=($(ldd /bin/cat | awk '{print $3}')); for i in $libs; do cp $i lofsdisk$(echo $i | sed 's/\/usr//'); done
cd lofsdick
./ex2.out >> ex2.txt

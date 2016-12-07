#!/bin/bash

# $1 is the first command line argument
# The [ ] evaluates a condition
# Semicolon ends a current line of the shell script and begins a new one

if [ "$1" != "" ] && [ "$2" != "" ]; then
# if the first & second cmd line arg exist, print
#echo "$1 and $2"
#elif [ "$1" != "" ]; then
#    echo "$1"
#else
#    echo "No command line arguments..."
g++ -std=c++11 -o qs quicksort_verbose.cpp
g++ -std=c++11 -o ms mergesort_verbose.cpp

COUNTER=0
for ((x=1; x<=$1; x++));
do
> num.txt
	for ((y=1; y<=$2; y++));
	do
		number=$RANDOM
		echo "$number" >> num.txt
	done
./ms num.txt > mergesort_failed_test_$x.txt
./qs num.txt 10 > quicksort_failed_test_$x.txt
DIFF=$(diff -u mergesort_failed_test_$x.txt quicksort_failed_test_$x.txt > diff.txt)
if [ "$DIFF" != "" ];
then COUNTER=$((COUNTER + 1))
else rm -rf mergesort_failed_test_$x.txt && rm -rf quicksort_failed_test_$x.txt
fi
done 
if [ "$COUNTER" == 0 ]; then
echo "All tests passed."
else 
echo "$COUNTER tests failed."
fi
rm -rf ms qs num.txt diff.txt
fi



#!/bin/bash

if [ "$1" != "" ] && [ "$2" != "" ] && [ "$3" != "" ]; then
g++ -std=c++11 -o qss quicksort_stats.cpp
g++ -std=c++11 -o mss mergesort_stats.cpp
g++ -std=c++11 -o qst quicksort_timed.cpp
g++ -std=c++11 -o mst mergesort_timed.cpp



echo Sample Number,Language,Time,Number of Partitioning Stages,Number of Exchanges,Number of Compares > quicksort.csv

echo Sample Number,Lannuage,Time,Number of Recursive Calls,Number of Transitions,Number of Compares > mergesort.csv
for ((x=1; x<=$2; x++));
do
> num.txt
        for ((y=1; y<=$3; y++));
        do
                number=$RANDOM
                echo "$number" >> num.txt
        done

echo $x,C++ >> quicksort.csv
echo $x,C++ >> mergesort.csv
#{ time qst num.txt 10 2>1 ; } 2> quicksort.csv


#time=$({./time mst num.txt} 2>&1) 
#$time >> quicksort.csv


#printf "%-d,c++,\n" "$x" >> quicksort.csv

done


fi

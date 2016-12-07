#!/bin/bash

compile=$(g++ -std=c++11 dselect_timed.cpp -o dselect_time)
echo -n "$compile"

compile=$(g++ -std=c++11 dselect_stats.cpp -o dselect_stats)
echo -n "$compile"

compile=$(g++ -std=c++11 quickselect_timed.cpp -o qselect_time)
echo -n "$compile"

compile=$(g++ -std=c++11 quickselect_stats.cpp -o qselect_stats)
echo -n "$compile"

compile=$(g++ -std=c++11 quicksort_select_timed.cpp -o quicksort_select_time)
echo -n "$compile"

compile=$(g++ -std=c++11 quicksort_select_stats.cpp -o quicksort_select_stats)
echo -n "$compile"



echo  -n "Sample,Datasize,QuickSelect Time,DeterministicSelect Time,QuickSortSelect Time,">"$1"_stat.csv
echo "QuickSelect Partitioning Stages,DeterministicSelect Partitioning Stages,QuicksSortSelect Partitioning Stages">>"$1"_stat.csv

for((i=1;i<=200;i++)); do

    echo -n "$i," >> "$1"_stat.csv

    echo -n "$1," >> "$1"_stat.csv

    k=$(shuf -i 1-$1 -n 1)


    #quickselect  
    realtime=$({ /usr/bin/time -f "%e" qselect_time experiment_sample$i.txt "$k"; } 2>&1)
    echo -n "$realtime">>"$1"_stat.csv
    echo -n "," >>"$1"_stat.csv

    #deterministicslect
    realtime=$({ /usr/bin/time -f "%e" dselect_time experiment_sample$i.txt "$k"; } 2>&1)
    echo -n "$realtime">>"$1"_stat.csv
    echo -n "," >>"$1"_stat.csv   

    #quicksortselect
    realtime=$({ /usr/bin/time -f "%e" quicksort_select_time experiment_sample$i.txt "$k"; } 2>&1)
    echo -n "$realtime">>"$1"_stat.csv
    echo -n "," >>"$1"_stat.csv



    #quickselect
    stats=$(./qselect_stats experiment_sample$i.txt "$k")
    echo "$stats" > output.txt
 
    while read -r line; do
    
      echo -n "$line" >> "$1"_stat.csv
      echo -n "," >>"$1"_stat.csv

    done < "output.txt"

    #deterministicslect
    stats=$(./dselect_stats experiment_sample$i.txt "$k")
    echo "$stats" > output.txt

    while read -r line; do

      echo -n "$line" >> "$1"_stat.csv
      echo -n "," >>"$1"_stat.csv

    done < "output.txt"

   
    stats=$(./quicksort_select_stats experiment_sample$i.txt "$k")
    echo "$stats" > output.txt

    while read -r line; do

      echo -n "$line" >> "$1"_stat.csv

    done < "output.txt"




    echo "">>"$1"_stat.csv
done




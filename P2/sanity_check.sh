#!/bin/bash

# {1..10} is the range of x, inclusive
# x in is part of a "for each" - it
compile=$(g++ -std=c++11 quickselect_verbose.cpp -o qselect)
echo -n "$compile"

compile=$(g++ -std=c++11 dselect_verbose.cpp -o dselect)
echo -n "$compile"

compile=$(g++ -std=c++11 quicksort_select_verbose.cpp -o quicksort_select)
echo -n "$compile" 


for ((i=1;i<=$1;i++)); do

   echo $2 > "sanity_sample$i.txt"
  
   generate=$(shuf -i 1-1000000 -n $2 >> "sanity_sample$i".txt) 
   echo -n "$generate"
  
done


for ((i=1;i<=$1;i++)); do
 
   k=$(shuf -i 1-$2 -n 1)
   #echo "k:$k"

   run=$(./qselect sanity_sample$i.txt $k >> qselectout.txt)
   echo  -n "$run"

  
   run=$(./dselect sanity_sample$i.txt $k >> dselectout.txt)
   echo  -n "$run"


   run=$(./quicksort_select sanity_sample$i.txt $k >> quicksort_selectout.txt)
   echo  -n "$run"

done


diff=$(diff3 qselectout.txt dselectout.txt quicksort_selectout.txt)
echo -n "$diff"

if [ "$diff" != "" ]; then 
   echo  $diff >> "failed_test.txt"
   echo "tests failed."
else
   echo "All tests passed."
fi
 

remove=$(rm *out.txt)
echo -n "$remove"
remove=$(rm sanity_sample*.txt)
echo -n "$remove"




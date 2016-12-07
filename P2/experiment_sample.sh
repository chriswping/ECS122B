#!/bin/bash

for ((i=1;i<=$1;i++)); do
   echo $2 > "experiment_sample$i.txt"
   
   generate=$(shuf -i 1-1000000 -n $2 >> "experiment_sample$i".txt)
   echo -n "$generate"

done


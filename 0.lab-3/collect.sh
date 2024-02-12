#!/bin/sh

# CLI syntax of sorter: ./Sorter <type> <count> NO
# need to tail last line of output to get time

# Create a file to store the results
rm results.csv
echo "Type,Count,ArrayType,Time" > results.csv

initalarraytypes=("random" "ordered" "partial" "reversed")
sorttypes=("BubbleSort" "InsertionSort" "MergeSort" "QuickSort" "ShellSort")

for sorttype in "${sorttypes[@]}"
do
  if [ "$sorttype" = "BubbleSort" ] || [ "$sorttype" = "InsertionSort" ]
  then
    runsizes=(100 1000 5000 10000 50000)
  else
    runsizes=(100 1000 5000 10000 50000 100000 500000 1000000)
  fi
  for arraytype in "${initalarraytypes[@]}"
  do
    for runsize in "${runsizes[@]}"
    do
      for i in {1..3}
      do
        output=($(./Sorter $sorttype $runsize YES $arraytype | tail -n 1))
        if [ $? != 0 ]
        then
          echo "Sorter failed at iteration $i, sorttype: $sorttype, runsize: $runsize, arraytype: $arraytype"
          exit 1
        fi
        res="$sorttype, $runsize, $arraytype, ${output[2]}"
        echo $res >> results.csv
        echo "Iteration $i of $sorttype, $runsize, $arraytype done"
      done
    done
  done
done
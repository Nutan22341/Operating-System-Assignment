#!/bin/bash

if [ ! -d "Result" ]; then
  mkdir Result
fi

while read line; do

  x=$(echo $line | cut -d' ' -f1)
  y=$(echo $line | cut -d' ' -f2)
  op=$(echo $line | cut -d' ' -f3)

  if [ "$op" == "xor" ]; then
    result=$((x ^ y))
  elif [ "$op" == "product" ]; then
    result=$((x * y))
  elif [ "$op" == "compare" ]; then
    if [ $x -gt $y ]; then
      result=$x
    else
      result=$y
    fi
  else
    echo "Invalid operation $op"
  fi

  echo $result >> Result/output.txt

done < input.txt


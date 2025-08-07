#!/bin/bash
read -p "enter the number of odd numbers n :" n
echo "The first $n odd numbers are:"
for (( i=1; i<=2*n-1; i+=2 )); do
echo "$i"
done

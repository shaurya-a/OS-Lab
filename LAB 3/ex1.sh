#!/bin/bash
echo "Enter the Number" n
read n
r=`expr $n % 2`
if [ $r -eq 0 ] 
then 
echo "$n is Even number"
else 
echo "$n is Odd number"
fi

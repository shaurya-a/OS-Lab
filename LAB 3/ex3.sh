#!/bin/bash
read a
read b
read c
d=$((b*b-4*a*c))
if ((d>=0)); then
calc=$(echo "sqrt ($d)" | bc )
x1=$((-b/2*a+calc/2*a))
x2=$((-b/2*a-calc/2*a))
echo "$x1""$x2"
else
echo "cant find"
fi


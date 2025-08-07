#!/bin/bash
read -p "Enter a:" a
read -p "Enter b:" b
read -p "Enter c:" c
d=$((b * b - 4 * a * c))
if ((d > 0)); then
    status="positive"
elif ((d == 0)); then
    status="zero"
else
    status="negative"
fi
case $status in
  positive|zero)
    sqrt_d=$(echo "sqrt($d)" | bc -l)
    d=$(echo "2 * $a" | bc -l)
    x1=$(echo "(-1 * $b + $sqrt_d) / $d" | bc -l)
    x2=$(echo "(-1 * $b - $sqrt_d) / $d" | bc -l)
    echo "Roots are:"
    echo "x1 = $x1"
    echo "x2 = $x2"
    ;;
  negative)
    echo "Can't find real roots Discriminant is negative"
    ;;
esac


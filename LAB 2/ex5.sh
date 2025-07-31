#!/bin/bash
file1="$1"
file2="$2"
cat "$file1" "$file2" | sort -n | uniq > merged_sorted_unique.txt


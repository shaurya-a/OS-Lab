#!/bin/bash
dir="$1"
for="$2"
ls "$dir" | grep ".$for"

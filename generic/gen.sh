#!/bin/bash
for((x=0;;x++)) 
do
	echo "Test number : " $x
	./gener $x >input.txt
	./pro <input.txt || break  
done 
cat input.txt

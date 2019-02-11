#!/bin/bash

if [ ! -d "./match random zz" ]; then


	gcc "match.c" -o match
	gcc "random.c" -o random
	gcc "always1000.c" -o always1000
	gcc "minus1.c" -o minus1
	gcc "zz.c" -o zz
	gcc "test.s" -o zz

fi

while [ 1 ]; do
    if ! ./match random zz 5; then 
        echo err
        break
    fi
done

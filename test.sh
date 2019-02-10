#!/bin/bash

while [ 1 ]; do
    if ! ./match random zz 5; then 
        echo err
        break
    fi
done
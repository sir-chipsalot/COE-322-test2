#!/bin/bash

# Check if an argument was provided
if [ $# -eq 0 ]; then
  echo "Error: No argument provided. Please provide a number."
  exit 1
fi

if [ $(($1 % 3)) -eq 0 ] && [ $(($1 % 5)) -eq 0 ] ; then
  echo "FizzBuzz"

elif [ $(($1 % 3)) -eq 0 ]; then
  echo "Fizz"

elif [ $(($1 % 5)) -eq 0 ]; then
  echo "Buzz"

else
  echo "This number is not divisible by 3 or 5"
fi

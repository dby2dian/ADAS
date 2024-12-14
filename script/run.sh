#!/bin/bash

if [ ! -f "build/tests/training_main" ]; then 
	echo "training_main not exists!"
	
	exit 0
fi

cd build/tests

./training_main

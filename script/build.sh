#!/bin/bash

bash script/clean.sh
mkdir -p build

cd build
cmake -G"Unix Makefiles" ..
make

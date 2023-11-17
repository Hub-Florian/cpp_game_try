#!/bin/bash

# Run CMake to generate build files (you can specify the build directory)
cmake -B build

# Compile the project using make (you can specify the number of CPU cores to use with -j)
cd build
make -j4  # Replace 4 with the desired number of CPU cores

# Move the executable to the desired location
mv ./src/DawnOfEvolution ../

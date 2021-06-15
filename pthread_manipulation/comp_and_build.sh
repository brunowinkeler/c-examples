#!/bin/bash

# ============= CLEANING WORKSPACE =============
rm -rf build
rm -rf install

# ============= BUILDING =============
mkdir -p build
cd build
cmake ..
make -j3
make install
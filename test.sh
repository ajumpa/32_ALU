#!/bin/bash
verilator -Wall -cc ALU.v --exe simulate.cpp
cd obj_dir && make -j -f VALU.mk
./VALU 1000 10000

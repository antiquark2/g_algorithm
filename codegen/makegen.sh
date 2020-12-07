#!/bin/sh

g++ -DABBREV -Wall -Wextra -pedantic -std=c++11 gen2.cpp -o gen_abbrev  2>&1 
g++  -Wall -Wextra -pedantic -std=c++11 gen2.cpp -o gen_full  2>&1 
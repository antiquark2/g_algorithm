#!/bin/sh

rm -f test test.out test.exe
 
gcc -DG_BASIC_ABBREV -Os -fdce -pipe -std=c11 -Wall -Wextra -pedantic -g g_algorithm.c test.c -o test 2>&1 
 

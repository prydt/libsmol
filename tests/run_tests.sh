#!/bin/sh
gcc *.c ../*.c -lcheck
./a.out
rm a.out

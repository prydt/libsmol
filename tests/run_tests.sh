#!/bin/sh
gcc *.c ../*.c -lcheck -lm
./a.out
rm a.out

#!/bin/sh
gcc -pipe -c -I/usr/local/include  -Wno-unused -fsigned-char -Wno-pointer-sign -o cobxref.o cobxref.c
gcc -pipe -Wl,--export-dynamic -o cobxref cobxref.o -L/usr/local/lib -lcob -lm -lgmp -lncurses -ldb

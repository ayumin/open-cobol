#!/bin/sh
cobc -x -O2 cobxref.cbl get-reserved-lists.cbl
chmod +x cobxref
exit



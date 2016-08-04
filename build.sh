#!/bin/bash
myinclude=`mysql_config --include`
mylib=`mysql_config --libs`

gcc -g -o mytest mytest.c $myinclude  $mylib


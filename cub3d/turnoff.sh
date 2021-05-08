#!/bin/bash

PROC=`cat list`
for i in $PROC
do
	kill -9 $i
done

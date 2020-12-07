#!/bin/sh

./test > output.txt

if diff output.txt good_output.txt
then
	echo "SUCCESS"
else
	echo "ERROR"
fi

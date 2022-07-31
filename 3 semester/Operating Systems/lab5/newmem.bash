#!/bin/bash
arr=()
while true
do
	arr+=(a$t b$t c$t d$t ab$t bc$t cd$t abc$t bcd$t abcd$t)
	if [ $1 -le "${#arr[*]}" ]
		then
			exit
	fi
done

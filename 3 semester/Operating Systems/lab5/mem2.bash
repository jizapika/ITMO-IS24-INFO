#!/bin/bash
arr=()
let t=1
> report2.log
while true
do
	arr+=(a$t b$t c$t d$t ab$t bc$t cd$t abc$t bcd$t abcd$t)
	if [[ t%100000 -eq 0 ]]
		then
			echo "${#arr[*]} words "$(date) >> report2.log
	fi
	let t=$t+1
done

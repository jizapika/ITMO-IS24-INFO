#!/bin/bash
> tracking_results
while true
do
	if [[ $(top -b -p $PPID) != "" ]]
		then
			top -b -p $PPID | awk '{print $5}' >> tracking_results
		else
			exit
	fi
	sleep 1
done

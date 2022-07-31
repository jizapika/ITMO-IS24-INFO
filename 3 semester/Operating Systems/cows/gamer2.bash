#!/bin/bash
file="game.txt"
let firstNumber=1
let secondNumber=2
let thirdNumber=3
for place in 1 2 3
do
	let bestNumber=0
	let maxValue=0
	while true
	do
		while [[ $thirdNumber -eq $firstNumber || $thirdNumber -eq $secondNumber ]]
		do
			let thirdNumber=$thirdNumber+1
		done
		if [[ $thirdNumber -gt 9 ]]
			then
				break
		fi
		echo $firstNumber$secondNumber$thirdNumber >> $file
		sleep 1
		tail -f $file | while read answer
		do
			if [[ $(echo $answer | awk '{print $1}') -gt $maxValue ]]
				then
					let bestNumber=$thirdNumber
					let maxValue=$(echo $answer | awk '{print $1}')
			fi
			break
		done
		let thirdNumber=$thirdNumber+1
		echo "bestNumber = "$bestNumber "maxValue = "$maxValue
	done
	if [[ $place -eq 1 ]]
		then
			let firstNumber=$bestNumber
			let thirdNumber=1
	fi
	if [[ $place -eq 2 ]]
		then
			let secondNumber=$bestNumber
			let thirdNumber=1
	fi
	if [[ $place -eq 3 ]]
		then
			let thirdNumber=$bestNumber
	fi
done
numbers=($firstNumber $secondNumber $thirdNumber)
for i in $numbers
do
	for j in $numbers
	do
		for k in $numbers
		do
			let counter=1
			if [[ $i -ne $j && $j -ne $k && $k -ne $i ]]
				then
					echo $i$j$k >> $file
s					sleep 1
					tail -f $file | while read answer
					do
						if [[ $(echo $answer | awk '{print $2}') -eq 3 ]]
							then
								echo "END" >> $file
								echo "The hidden number is a $i$j$k"
								exit
						fi
					done
			fi
		done
	done
done

#!/bin/bash
file="game.txt"
if [[ -r $file ]]
	then
		rm $file
fi
touch $file
let hiddenNumber1=$RANDOM%9+1
let hiddenNumber2=$RANDOM%9+1
let hiddenNumber3=$RANDOM%9+1
while [[ $hiddenNumber2 -eq $hiddenNumber1 ]]
do
	let hiddenNumber2=$RANDOM%9+1
done
while [[ $hiddenNumber3 -eq $hiddenNumber1 || $hiddenNumber3 -eq $hiddenNumber2 ]]
do
	let hiddenNumber3=$RANDOM%9+1
done
let hiddenNumber=$hiddenNumber1*100+$hiddenNumber2*10+$hiddenNumber3
echo "Hidden number is "$hiddenNumber
(tail -f $file) | while read estimatedNumber
do
	echo $estimatedNumber
	if [[ $estimatedNumber == "END" ]]
		then
			exit
	fi
	let estimatedNumber1=$estimatedNumber/100
	let estimatedNumber2=$estimatedNumber/10%10
	let estimatedNumber3=$estimatedNumber%10
	let matchingNumbers=0
	let matchingPlaces=0
	for hidden in $hiddenNumber1 $hiddenNumber2 $hiddenNumber3
	do
		for estimated in $estimatedNumber1 $estimatedNumber2 $estimatedNumber3
		do
			if [[ $hidden -eq $estimated ]]
				then
					let matchingNumbers=$matchindNumbers+1
			fi
		done
	done
	if [[ $hiddenNumber1 -eq $estimatedNumber1 ]]
		then
			let matchingPlaces=$matchingPlaces+1
	fi
	if [[ $hiddenNumber2 -eq $estimatedNumber2 ]]
		then
			let matchingPlaces=$matchingPlaces+1
	fi
	if [[ $hiddenNumber3 -eq $estimatedNumber3 ]]
		then
			let matchingPlaces=$matchingPlaces+1
	fi
	echo $matchingNumbers $matchingPlaces >> $file
	sleep 1
done

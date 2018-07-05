#!/bin/bash

function usage () {
	echo "usage: ./metrics [--details] data"
}

function nb_malloc () {
	NB_MALLOC=$(cat $FILE | grep malloc | wc -l)
}

function nb_free () {
	NB_FREE=$(cat $FILE | grep free | wc -l)
}

function nb_defrag () {
	NB_DEFRAG=$(cat $FILE | grep defrag | wc -l)
}

function nb_first_block () {
	NB_POS_BLOCK=$(cat $FILE | grep "malloc 1eol" | wc -l)
}

function nb_second_block () {
	NB_POS_BLOCK=$(cat $FILE | grep "malloc 2eol" | wc -l)
}

function nb_third_block () {
	NB_POS_BLOCK=$(cat $FILE | grep "malloc 3eol" | wc -l)
}

function nb_fourth_block () {
	NB_POS_BLOCK=$(cat $FILE | grep "malloc 4eol" | wc -l)
}

function nb_fifth_block () {
	NB_POS_BLOCK=$(cat $FILE | grep "malloc 5eol" | wc -l)
}

function nb_sixth_block () {
	NB_POS_BLOCK=$(cat $FILE | grep "malloc 6eol" | wc -l)
}

function ratio_block () {
	bc <<< $(($NB_POS_BLOCK * 100 / $NB_MALLOC))
}

function blocks_merged () {
	BLOCKS_MERGED=$(bc <<< $(($NB_DEFRAG * 2)))
}

function main () {
	if [ -z "$1" ]
	then
		usage
		exit 1
	elif [ "$1" == "--details" ]; then
		OPTION=1
		FILE=$2
	else
		FILE=$1
		OPTION=0
	fi

	if [ -z "$FILE" ]
	then
		usage
		exit 1
	fi

	echo "--- MALLOC ---"
	nb_malloc
	printf "%s\n" "Amount of malloc: $NB_MALLOC"
	
	nb_first_block
	printf "\t%s\t%s\t" "- 1st block chosen: $NB_POS_BLOCK" "Ratio (%): "
	ratio_block

	nb_second_block
	printf "\t%s\t%s\t" "- 2nd block chosen: $NB_POS_BLOCK" "Ratio (%): "
	ratio_block

	nb_third_block
	printf "\t%s\t%s\t" "- 3rd block chosen: $NB_POS_BLOCK" "Ratio (%): "
	ratio_block

	if [ $OPTION -eq 1 ]
	then
		nb_fourth_block
		printf "\t%s\t%s\t" "- 4th block chosen: $NB_POS_BLOCK" "Ratio (%): "
		ratio_block

		nb_fifth_block
		printf "\t%s\t%s\t" "- 5th block chosen: $NB_POS_BLOCK" "Ratio (%): "
		ratio_block

		nb_sixth_block
		printf "\t%s\t%s\t" "- 6th block chosen: $NB_POS_BLOCK" "Ratio (%): "
		ratio_block
	fi
	echo "--- FREE ---"
	nb_free
	printf "%s\n" "Amount of free: $NB_FREE"

	nb_defrag
	blocks_merged
	printf "%s\n" "Defragmentation: $NB_DEFRAG times, meaning $BLOCKS_MERGED blocks merged."
	
	echo "--------------"
}

main "$@"

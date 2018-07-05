#!/bin/bash

function usage () {
	echo "usage: ./metrics data"
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
	fi

	FILE=$1
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

	echo "--- FREE ---"
	nb_free
	printf "%s\n" "Amount of free: $NB_FREE"

	nb_defrag
	blocks_merged
	printf "%s\n" "Defragmentation: $NB_DEFRAG times, meaning $BLOCKS_MERGED blocks merged."
	
	echo "--------------"
}

main "$@"

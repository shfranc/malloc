#!/bin/bash

function nb_malloc () {
	NB_MALLOC=$(cat stats | grep malloc | wc -l)
}

function nb_free () {
	NB_FREE=$(cat stats | grep free | wc -l)
}

function nb_defrag () {
	NB_DEFRAG=$(cat stats | grep defrag | wc -l)
}

function nb_first_block () {
	cat stats | grep malloc > tmp
	NB_POS_BLOCK=$(fgrep -o 1 tmp | wc -l)
	rm  -f tmp
}

function nb_second_block () {
	cat stats | grep malloc > tmp
	NB_POS_BLOCK=$(fgrep -o 2 tmp | wc -l)
	rm  -f tmp
}

function nb_third_block () {
	cat stats | grep malloc > tmp
	NB_POS_BLOCK=$(fgrep -o 3 tmp | wc -l)
	rm  -f tmp
}

function ratio_block () {
	bc <<< $(($NB_POS_BLOCK * 100 / $NB_MALLOC))
}

function blocks_merged () {
	BLOCKS_MERGED=$(bc <<< $(($NB_DEFRAG * 2)))
}

function main () {
	echo "--- MALLOC ---"
	nb_malloc
	printf "%s\n" "Number of malloc: $NB_MALLOC"
	
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
	printf "%s\n" "Number of free: $NB_FREE"

	nb_defrag
	blocks_merged
	printf "%s\n" "Defragmentation: $NB_DEFRAG times, meaning $BLOCKS_MERGED blocks merged."
	
	echo "--------------"
}

main "$@"

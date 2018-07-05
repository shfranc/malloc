#include <stdio.h> // printf
#include <stdlib.h> // malloc, atoi
#include <string.h> // memset
#include <unistd.h> // write
#include <time.h> // time

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	long int size = atol(argv[1]);
	char* str = (char*)malloc(size);
	if (str)
		printf("malloc done.\n");
	else
		printf("malloc failed (NULL).\n");

	for (int i = 0; i < size; i++)
	{
		str[i] = rand() % 128;
		if (i < 100)
			write(1, &str[i], 1);
	}
	// memset(str, '*', size - 1);
	printf("Memset of size=argv[1] : done. \n");
	
	while (1);
	return 0;
}
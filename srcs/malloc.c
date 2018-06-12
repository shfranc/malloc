#include "malloc.h"

void	*malloc(size_t size)
{
	char	*ret;

	write(1, "malloc!\n", 8);
	ret = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return ret;
}

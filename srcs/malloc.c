#include "malloc.h"

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	*malloc(size_t size)
{
	char	*ret;

	ft_putnbr_str("malloc: ", size);
	ret = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return ret;
}

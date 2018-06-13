#include "malloc.h"

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	*malloc(size_t size)
{
	char	*ret;
	t_block		block;

	block.size = size;
	block.free = 0;

	ft_putnbr_str("size of t_block: ", sizeof(t_block));
	ft_putnbr_str("size of block: ", sizeof(block));
	ft_putnbr_str("malloc: ", size);
	ft_putnbr_str("malloc: ", size);

	ret = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	return ret;
}

#include "malloc.h"

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	*malloc(size_t size)
{
	unsigned int	type;
	t_block			*block;

	size = ft_align_size(size, 16);
	ft_putnbr_str("size:", size);

	type = ft_choose_pool(size);
	ft_putnbr_str("type:", type);

	if (!g_heap[type].free)
		g_heap[type].free = ft_extend_free_pool(NULL, type, size);

	block = ft_choose_free_block(type, size);
	// should we split it ?

	ft_move_block_to_use(type, block);
	
	ft_putaddr_endl((unsigned long long)block);
	ft_putnbr_str("data:", block->size);

	return (NULL);
}

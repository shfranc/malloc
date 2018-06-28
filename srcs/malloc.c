#include "malloc.h"

static int		ft_choose_pool(size_t size)
{
	if (size <= TINY_BLOCK)
		return (TINY);
	else if (size <= SMALL_BLOCK)
		return (SMALL);
	else
		return (LARGE);
}

void	*malloc(size_t size)
{
	unsigned int	type;
	t_block			*block;

	// ft_putendl(BLUE"MALLOC"RESET);

	size = ft_align_size(size, 16);
	// ft_putnbr_str("size:", size);

	type = ft_choose_pool(size);
	// ft_putnbr_str("type:", type);

	if (!g_heap[type].free)
		g_heap[type].free = ft_extend_free_pool(NULL, type, size);

	block = ft_choose_free_block(type, size);

	if (type == TINY || type == SMALL)
		block->next = ft_split_block(block, type, size);

	ft_move_block_to_use(type, block);

	// ft_putaddr_endl((unsigned long long)block);
	// ft_putaddr_endl((unsigned long long)((char*)block + ft_header_size()));

	// show_alloc_mem();
	ft_print_debug(1, block);

	return ((void*)((char*)block + ft_header_size()));
}

#include "malloc.h"

int g_debug = 1;

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

	g_debug ? ft_putendl("\n\t\tMALLOC") : 0;
	
	size = ft_align_size(size, 16);
	// ft_putnbr_str("size:", size);

	type = ft_choose_pool(size);
	// ft_putnbr_str("type:", type);

	if (type == TINY || type == SMALL)
	{
		block = ft_choose_free_block(type, size);
		block->next = ft_split_block(block, type, size);
	}
	else
		block = ft_add_free_block(NULL, type, size);

	ft_move_block_to_use(type, block);

	// ft_putaddr_endl((unsigned long long)block);
	// ft_putaddr_endl((unsigned long long)((char*)block + ft_header_size()));

	// show_alloc_mem();
	g_debug ? ft_print_debug(1, block) : 0;
	g_debug ? show_alloc_mem() : 0;

	return ((void*)((char*)block + ft_header_size()));
}

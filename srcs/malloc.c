#include "malloc.h"

int g_debug = 0;

t_block		*ft_alloc_large(size_t size)
{
	t_block 	*block;
	size_t		pages;

	pages = ft_align_size(size + ft_header_size(), getpagesize());
	block = ft_request_memory(NULL, pages);
	block->size = pages - ft_header_size();
	block->prev = NULL;
	block->next = NULL;
	ft_insert_block_top(&g_heap[LARGE].in_use, block);
	return (block);
}

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
		if (!block)
			return (NULL);
		block->next = ft_split_block(block, type, size);
		ft_move_block_to_use(type, block);
	}
	else
	{
		block = ft_alloc_large(size);
	}

	// ft_putaddr_endl((unsigned long long)block);
	// ft_putaddr_endl((unsigned long long)((char*)block + ft_header_size()));

	// show_alloc_mem();
	g_debug ? ft_print_debug(1, block) : 0;
	g_debug ? show_alloc_mem() : 0;

	return ((void*)((char*)block + ft_header_size()));
}

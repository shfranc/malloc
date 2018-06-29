#include "malloc.h"
#include <stdio.h>

t_block		*ft_search_heap(t_block *blocks, void *ptr)
{
	t_block 	*block;
	
	g_debug ? ft_putstr("searching for ") : 0;
	g_debug ? ft_putaddr((unsigned long long)ptr) : 0;
	g_debug ? ft_putstr(" in ") : 0;
	g_debug ? ft_putaddr_endl((unsigned long long)blocks) : 0;
	block = blocks;
	while (block)
	{
		// ft_putstr("data: ");
		// ft_putaddr_endl((unsigned long long)((char*)block + ft_header_size()));

		if ((char*)block + ft_header_size() == (char*)ptr)
			return (block);

		block = block->next;
	}
	return (NULL);
}

int 	ft_find_used_block(void *ptr, t_block **block)
{
	if ((*block = ft_search_heap(g_heap[LARGE].in_use, ptr)))
	{
		g_debug ? ft_putendl("ft_find_used_block: found ! in LARGE") : 0;
		return (LARGE);
	}
	else if ((*block = ft_search_heap(g_heap[SMALL].in_use, ptr)))
	{
		g_debug ? ft_putendl("ft_find_used_block: found ! in SMALL") : 0;
		return (SMALL);
	}
	else if ((*block = ft_search_heap(g_heap[TINY].in_use, ptr)))
	{
		g_debug ? ft_putendl("ft_find_used_block: found ! in TINY") : 0;
		return (TINY);
	}
	g_debug ? ft_putendl("ft_find_used_block: not found...") : 0;
	return (-1);
}

void	ft_move_block_to_free(int type, t_block *block)
{
	g_debug ? ft_putnbr_str("ft_move_block_to_free: type", type) : 0;

	g_debug ? ft_putstr("ft_delete_block: ") : 0;
	g_debug ? ft_print_pool(type) : 0;
	g_debug ? ft_list_len(g_heap[type].in_use) : 0;
	ft_delete_block(&g_heap[type].in_use, block);
	g_debug ? ft_list_len(g_heap[type].in_use) : 0;

	g_debug ? ft_putnbr_str("ft_move_block_to_use: type", type) : 0;
	if (!ft_insert_block_addr(&g_heap[type].free, block))
		ft_insert_block_top(&g_heap[type].free, block);
}

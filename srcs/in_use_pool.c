#include "malloc.h"
#include <stdio.h>

t_block		*ft_search_heap(t_block *blocks, void *ptr)
{
	t_block 	*block;
	
	ft_putstr("searching for ");
	ft_putaddr((unsigned long long)ptr);
	ft_putstr(" in ");
	ft_putaddr_endl((unsigned long long)blocks);
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
	if ((*block = ft_search_heap(g_heap[TINY].in_use, ptr)))
	{
		ft_putendl("ft_find_used_block: found ! in TINY");
		return (TINY);
	}
	else if ((*block = ft_search_heap(g_heap[SMALL].in_use, ptr)))
	{
		ft_putendl("ft_find_used_block: found ! in SMALL");
		return (SMALL);
	}
	else if ((*block = ft_search_heap(g_heap[LARGE].in_use, ptr)))
	{
		ft_putendl("ft_find_used_block: found ! in LARGE");
		return (LARGE);
	}
	ft_putendl("ft_find_used_block: not found...");
	return (-1);
}

void	ft_move_block_to_free(int type, t_block *block)
{
	ft_putstr("ft_delete_block: ");
	ft_print_pool(type);
	ft_list_len(g_heap[type].in_use);
	ft_delete_block(&g_heap[type].in_use, block);
	ft_list_len(g_heap[type].in_use);

	if (!ft_insert_block_addr(&g_heap[type].free, block))
		ft_insert_block_top(&g_heap[type].free, block);
}

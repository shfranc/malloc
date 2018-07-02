#include "malloc.h"

t_block		*ft_choose_free_block(int type, size_t size)
{
	t_block		*block;
	t_block		*last;
	int 		i;

	i = 0;
	block = g_heap[type].free;
	g_debug ? ft_print_pool(type) : 0;
	last = NULL;
	while (block)
	{
		i++;
		last = block;
		if (block->size >= size)
		{
			g_debug ? ft_putstr("n* block:") : 0;
			g_debug ? ft_putnbr(i) : 0;
			g_debug ? ft_putstr(" / ") : 0;
			g_debug ? ft_list_len(g_heap[type].free) : 0;
			g_debug ? ft_putstr("ft_choose_free_block: ") : 0;
			g_debug ? ft_show_block_full(block) : 0;
			STAT ? ft_stat_malloc(i) : 0;
			return (block);
		}
		block = block->next;
	}
	return (ft_add_free_block(last, type, size));
}

t_block 		*ft_add_free_block(t_block *last, int type, size_t size)
{
	g_debug ? ft_putendl("ft_choose_free_block: extend heap ICI - size not big enough") : 0;
	if (last)
	{
		g_debug ? ft_putendl("ft_add_free_block: extend last") : 0;
		last->next = ft_extend_free_pool(last, type, size);
		return (last->next);
	}
	else
	{
		g_debug ? ft_putendl("ft_add_free_block: free is empty") : 0;
		g_heap[type].free = ft_extend_free_pool(last, type, size);
		return (g_heap[type].free);
	}
}

t_block		*ft_extend_free_pool(void *last, int type, size_t size)
{
	t_block 	*block;
	size_t		pages;

	if (type == TINY)
		pages = ft_align_size(NB_BLOCKS * (TINY_BLOCK + ft_header_size()), getpagesize());
	else if (type == SMALL)
		pages = ft_align_size(NB_BLOCKS * (SMALL_BLOCK + ft_header_size()), getpagesize());		
	else
		pages = ft_align_size(size + ft_header_size(), getpagesize());

	block = ft_request_memory(last + ft_header_size(), pages);
	block->size = pages - ft_header_size();
	block->prev = last;
	block->next = NULL;
	g_debug ? ft_putnbr_str("ft_extend_free_pool:", block->size) : 0;

	return(block);
}

t_block		*ft_request_memory(void *last, size_t size)
{
	t_block *tmp;
	
	if ((tmp = mmap(last, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	return (tmp);
}

void		ft_move_block_to_use(int type, t_block *block)
{
	g_debug ? ft_putnbr_str("ft_move_block_to_use: type", type): 0;
	g_debug ? ft_putstr("ft_delete_block: ") : 0;
	g_debug ? ft_print_pool(type) : 0;
	g_debug ? ft_list_len(g_heap[type].free) : 0;
	ft_delete_block(&g_heap[type].free, block);
	g_debug ? ft_list_len(g_heap[type].free) : 0;
	
	ft_insert_block_top(&g_heap[type].in_use, block);
}

#include "malloc.h"

t_block		*ft_choose_free_block(int type, size_t size)
{
	t_block		*block;
	t_block		*last;
	int 		i;

	i = 0;
	block = g_heap[type].free;
	ft_print_pool(type);
	last = NULL;
	while (block)
	{
		i++;
		last = block;
		if (block->size >= size)
		{
			ft_putstr("n* block:");
			ft_putnbr(i);
			ft_putstr(" / ");
			ft_list_len(g_heap[type].free);
			ft_putstr("ft_choose_free_block: ");
			ft_show_block_full(block);
			return (block);
		}
		block = block->next;
	}

	if (!block) // useless ?? Non, les tous les block sont0 trop petits !
	{
		ft_putendl("ft_choose_free_block: extend heap ICI - size not big enough");
		if (last)
		{
			ft_putendl("extend last");
			last->next = ft_extend_free_pool(last, type, size);
			return (last->next);
		}
		else
		{
			ft_putendl("free is empty");
			g_heap[type].free = ft_extend_free_pool(last, type, size);
			return (g_heap[type].free);
		}
	}
	ft_putendl("YOU SHALL NOT PASS");
	return (NULL);
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
	ft_putnbr_str("ft_extend_free_pool:", block->size);

	return(block);
}

t_block		*ft_request_memory(void *last, size_t size)
{
	return (mmap(last, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0));
}

void		ft_move_block_to_use(int type, t_block *block)
{
	ft_putstr("ft_delete_block: ");
	ft_print_pool(type);
	ft_list_len(g_heap[type].free);
	ft_delete_block(&g_heap[type].free, block);
	ft_list_len(g_heap[type].free);
	
	ft_insert_block_top(&g_heap[type].in_use, block);
}


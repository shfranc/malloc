#include "malloc.h"

int		ft_choose_pool(size_t size)
{
	if (size <= TINY_BLOCK)
		return (TINY);
	else if (size <= SMALL_BLOCK)
		return (SMALL);
	else
		return (LARGE);
}

t_block		*ft_choose_free_block(int type, size_t size)
{
	t_block		*block;
	t_block		*last;

	block = g_heap[type].free;
	while (block)
	{
		last = block;
		if (block->size >= size)
			return (block);
		block = block->next;
	}

	if (!block)
	{
		last->next = ft_extend_free_pool(last->next + ft_header_size(), type, size); 
	}

	return (block);
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

	block = ft_request_memory(last, pages);
	block->size = pages;
	block->prev = last - ft_header_size();
	block->next = NULL;

	return(block);
}

void	*ft_request_memory(void *last, size_t size)
{
	return (mmap(last, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0));
}
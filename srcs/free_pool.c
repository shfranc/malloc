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
		ft_putendl("extend heap");
		if (last)
			last->next = ft_extend_free_pool(last, type, size);
		else //
			g_heap[type].free = ft_extend_free_pool(NULL, type, size); // utile... ?
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

	block = ft_request_memory(last + ft_header_size(), pages);
	block->size = pages - ft_header_size();
	block->prev = last;
	block->next = NULL;

	return(block);
}

t_block	*ft_request_memory(void *last, size_t size)
{
	return (mmap(last, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0));
}

void		ft_delete_block(t_block **start, t_block *block)
{
	if (block->prev)
		block->prev->next = block->next;
	else
		*start = block->next;

	if (block->next)
		block->next->prev = block->prev;
}

void		ft_insert_block_top(t_block **start, t_block *block)
{
	if (!*start)
	{
		*start = block;
		block->next = NULL;
		block->prev = NULL;
	}
	else
	{
		(*start)->prev = block;
		block->next = *start;
		block->prev = NULL;
		*start = block;
	}
}

void		ft_move_block_to_use(int type, t_block *block)
{
	// suppr from free list
	// ft_putendl("--- free");
	// ft_show_heap(g_heap[type].free);
	// ft_putendl("--- free");

	ft_delete_block(&g_heap[type].free, block);

	// ft_putendl("--- free");
	// ft_show_heap(g_heap[type].free);
	// ft_putendl("--- free");

	// insert to in_use
	ft_insert_block_top(&g_heap[type].in_use, block);

	// ft_putendl("--- in use");
	// ft_show_heap(g_heap[type].in_use);
	// ft_putendl("--- in use");

}
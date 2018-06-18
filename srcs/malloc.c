#include "malloc.h"

size_t 		ft_align_size(size_t size, size_t n)
{
	if (size == 0)
		return (n);
	return (((((size) - 1) / n) * n) + n);
}

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	*ft_tiny_heap(size_t size)
{
	void		*ret;

	if (!g_handler.tiny.start)
		g_handler.tiny.start = ft_extend_heap(0, ft_align_size(EXTEND_TINY, getpagesize()));
	
	if (!(ret = ft_find_block(&g_handler.tiny, size)))
	{
		g_handler.tiny.last->next = ft_extend_heap(g_handler.tiny.last->data + g_handler.tiny.last->size, ft_align_size(EXTEND_TINY, getpagesize()));		
		ret = ft_find_block(&g_handler.tiny, size);
	}

	ft_print_heap(&g_handler.tiny);
	ft_print_blocks(&g_handler.tiny);

	return ret;
}

void	*ft_small_heap(size_t size)
{
	void		*ret;

	if (!g_handler.small.start)
		g_handler.small.start = ft_extend_heap(0, ft_align_size(EXTEND_TINY, getpagesize()));
	
	if (!(ret = ft_find_block(&g_handler.small, size)))
	{
		g_handler.small.last->next = ft_extend_heap(g_handler.small.last->data + g_handler.small.last->size, ft_align_size(EXTEND_TINY, getpagesize()));		
		ret = ft_find_block(&g_handler.small, size);
	}

	ft_print_heap(&g_handler.small);
	ft_print_blocks(&g_handler.small);

	return ret;
}

void	*ft_large_heap(size_t size)
{
	if (!g_handler.large.start)
	{
		ft_putendl("initialisation");
		g_handler.large.start = ft_extend_heap(0, ft_align_size(size, getpagesize()));
		g_handler.large.last = g_handler.large.start;
		ft_putendl("initialisation");
	}
	else
		g_handler.large.last->next = ft_extend_heap(g_handler.large.last->data + g_handler.large.last->size, ft_align_size(size, getpagesize()));
	ft_putendl("initialisation");

	g_handler.large.last->free = 0;
	
	ft_putendl("initialisation");
	
	g_handler.large.mapped += size + BLOCK_SIZE;
	
	ft_print_heap(&g_handler.large);
	ft_print_blocks(&g_handler.large);

	return (g_handler.large.last->data);
}

void	*malloc(size_t size)
{
	void		*ret;
	
	// if (size == 0) // size == -1 a gerer
		// return (NULL);

	size = ft_align_size(size, 16);
	if (size <= TINY)
		ret = ft_tiny_heap(size);
	else if (size <= SMALL)
		ret = ft_small_heap(size);
	else
		ret = ft_large_heap(size);

	return ret;
}

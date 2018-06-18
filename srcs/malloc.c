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
		ft_extend_heap(&g_handler.tiny, ft_align_size(EXTEND_TINY, getpagesize()));
	
	if (!(ret = ft_find_block(&g_handler.tiny, size)))
	{
		ft_extend_heap(&g_handler.tiny, ft_align_size(EXTEND_TINY, getpagesize()));		
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
		ft_extend_heap(&g_handler.small, ft_align_size(EXTEND_SMALL, getpagesize()));		
	
	if (!(ret = ft_find_block(&g_handler.small, size)))
	{
		ft_extend_heap(&g_handler.small, ft_align_size(EXTEND_SMALL, getpagesize()));		
		ret = ft_find_block(&g_handler.small, size);
	}

	ft_print_heap(&g_handler.small);
	ft_print_blocks(&g_handler.small);

	return ret;
}

void	*ft_large_heap(size_t size)
{
	ft_extend_heap(&g_handler.large, ft_align_size(size, getpagesize()));
	
	g_handler.large.last->free = 0;
	g_handler.large.mapped += size + BLOCK_SIZE;
	
	ft_print_heap(&g_handler.large);
	ft_print_blocks(&g_handler.large);
	return (g_handler.large.last->data);
}

void	*malloc(size_t size)
{
	void		*ret;
	
	// if (size == 0)
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

#include "malloc.h"

// (((((x)-1)>>2)<<2)+4)

size_t 		ft_align_size(size_t size)
{
	return (((((size) - 1) >> 4) << 4) + 16);
}

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	*ft_tinysmall_heap(t_heap *heap, size_t size)
{
	void		*ret;

	if (!heap->start)
		ft_extend_heap(heap);
	
	if (!(ret = ft_find_block(heap, size)))
	{
		ft_extend_heap(heap);
		ret = ft_find_block(heap, size);
	}

	ft_print_heap(heap);
	ft_print_blocks(heap);

	return ret;
}

void	*malloc(size_t size)
{
	void		*ret;
	
	if (size == 0)
		return (NULL);
	size = ft_align_size(size);
	if (size <= TINY)
		ret = ft_tinysmall_heap(&g_handler.tiny, size);
	else if (size <= LARGE)
		ret = ft_tinysmall_heap(&g_handler.small, size);
	else
		ret = ft_large_heap(&g_handler.large, size);

	// if (!g_handler.tiny.start)
	// 	ft_extend_heap(&g_handler.tiny);
	
	
	// if (!(ret = ft_find_block(&g_handler.tiny, size)))
	// {
	// 	ft_extend_heap(&g_handler.tiny);
	// 	ret = ft_find_block(&g_handler.tiny, size);
	// }

	// ft_print_heap(&g_handler.tiny);
	// ft_print_blocks(&g_handler.tiny);

	return ret;
}

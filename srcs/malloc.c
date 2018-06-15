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

void	*malloc(size_t size)
{
	void		*ret;


	ret = NULL;

	if (size == 0)
		return (NULL);

	if (!g_heap.start)
	{
		ft_extend_heap();
		// ft_print_heap();
		// ft_print_blocks(g_heap.start);
	}
	
	size = ft_align_size(size);
	
	if (!(ret = ft_find_block(size)))
	{
		ft_extend_heap();
		// ft_print_heap();
		// ft_print_blocks(g_heap.start);
		ret = ft_find_block(size);
	}

	// ft_print_heap();
	ft_print_blocks(g_heap.start);

	return ret;
}

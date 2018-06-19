#include "malloc.h"

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	*ft_tiny_heap(size_t size)
{
	void		*ret;

	if (!g_handler.tiny.start)
		ft_init_heap(&g_handler.tiny, ft_align_size(EXTEND_TINY, getpagesize()));
	
	if (!(ret = ft_find_block(&g_handler.tiny, size)))
	{
		g_handler.tiny.last->next = ft_extend_heap(g_handler.tiny.last->data + g_handler.tiny.last->size, ft_align_size(EXTEND_TINY, getpagesize()));
		g_handler.tiny.last = g_handler.tiny.last->next;
		ret = ft_add_block(g_handler.tiny.last, size);		
	}

	ft_print_heap(&g_handler.tiny);
	ft_print_blocks(&g_handler.tiny);

	return ret;
}

void	*ft_small_heap(size_t size)
{
	void		*ret;

	if (!g_handler.small.start)
		ft_init_heap(&g_handler.small, ft_align_size(EXTEND_SMALL, getpagesize()));
	
	if (!(ret = ft_find_block(&g_handler.small, size)))
	{
		ft_putendl("on aggrandit la heap");
		g_handler.small.last->next = ft_extend_heap(g_handler.small.last->data + g_handler.small.last->size, ft_align_size(EXTEND_TINY, getpagesize()));		
		g_handler.small.last = g_handler.small.last->next;

		ret = ft_add_block(g_handler.small.last, size);
	}

	ft_print_heap(&g_handler.small);
	ft_print_blocks(&g_handler.small);

	return ret;
}

void	*ft_large_heap(size_t size)
{
	// void		*ret;

	if (!g_handler.large.start)
	{
		ft_init_heap(&g_handler.large, ft_align_size(size, getpagesize()));
	}
	else
	{
		g_handler.large.last->next = ft_extend_heap(g_handler.large.last->data + g_handler.large.last->size, ft_align_size(size, getpagesize()));
		g_handler.large.last = g_handler.large.last->next;
	}

	g_handler.large.last->free = 0;
	
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

#include "malloc.h"

void	ft_print_heap(t_heap *heap)
{
		ft_putendl("---------------------------------");
		ft_putstr(RED);
		ft_putstr("HEAP - start: ");
		ft_putaddr_endl((unsigned long long)(heap->start));
		ft_putstr("HEAP - last: ");
		ft_putaddr_endl((unsigned long long)(heap->last));
		ft_putendl(RESET);
}

void		ft_init_heap(t_heap *heap, size_t size)
{
	heap->start = ft_extend_heap(0, ft_align_size(size, getpagesize()));
	heap->last = g_handler.large.start;
}

t_block		*ft_extend_heap(void *last, size_t size)
{
	void		*page;
	t_block		*block;


	page = mmap(last, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	
	block = (t_block*)page;
	ft_init_block(block, size);

	return block;
}
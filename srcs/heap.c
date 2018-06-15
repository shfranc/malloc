#include "malloc.h"

void	ft_print_heap(t_heap *heap)
{
		ft_putendl("---------------------------------");
		ft_putstr(RED);
		ft_putstr("HEAP - start: ");
		ft_putaddr_endl((unsigned long long)(heap->start));
		ft_putstr("HEAP - last: ");
		ft_putaddr_endl((unsigned long long)(heap->last));
		ft_putnbr_str("HEAP - mapped: ", heap->mapped);
		ft_putnbr_str("HEAP - total: ", heap->total);
		ft_putendl(RESET);
}

void	ft_extend_heap(t_heap	*heap)
{
	void		*page;
	t_block		*block;

	page = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0); // demander à mmap des plages qui se suivent
	
	block = (t_block*)page;	
	ft_init_block(block, getpagesize());

	heap->total += getpagesize();
	heap->mapped += BLOCK_SIZE;
	
	if (heap->last)
	{
		if (!ft_fusion_block(heap, heap->last, block))
			heap->last->next = block;
	}
	else
	{
		heap->start = block;
		heap->last = block;
	}
	
	return;
}
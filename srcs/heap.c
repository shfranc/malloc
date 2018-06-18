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

// void	ft_extend_heap(t_heap	*heap, size_t size)
// {
// 	void		*page;
// 	void		*start;
// 	t_block		*block;

// 	start = heap->last ? heap->last->next : 0;

// 	page = mmap(start, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	
// 	block = (t_block*)page;	
// 	ft_init_block(block, size);

// 	heap->total += size;
// 	heap->mapped += BLOCK_SIZE;
	
// 	if (heap->last)
// 	{
// 		// if (!ft_fusion_block(heap, heap->last, block))
// 			heap->last->next = block;
// 	}
// 	else
// 	{
// 		heap->start = block;
// 		heap->last = block;
// 	}
	
// 	return;
// }

t_block		*ft_extend_heap(void *last, size_t size)
{
	void		*page;
	t_block		*block;


	page = mmap(last, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	
	block = (t_block*)page;
	ft_init_block(block, size);

	heap->total += size;
	heap->mapped += BLOCK_SIZE;
	
	return t_block;
}
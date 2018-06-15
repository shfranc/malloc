#include "malloc.h"

void	ft_print_heap(void)
{
		ft_putstr(RED);
		ft_putstr("HEAP - start: ");
		ft_putaddr((unsigned long long)(g_heap.start));
		ft_putstr("HEAP - last: ");
		ft_putaddr((unsigned long long)(g_heap.last));
		ft_putnbr_str("HEAP - mapped: ", g_heap.mapped);
		ft_putnbr_str("HEAP - total: ", g_heap.total);
		ft_putendl(RESET);
}

void	ft_extend_heap(void)
{
	void		*page;
	t_block		*block;

	page = mmap(0, getpagesize(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	
	block = (t_block*)page;	
	ft_init_block(block, getpagesize());

	g_heap.total += getpagesize();
	g_heap.mapped += BLOCK_SIZE;
	
	if (g_heap.last)
	{
		if (g_heap.last->free)
			g_heap.last->size += block->size; // les plages ne sont pas forcément continues !!
		else
			g_heap.last->next = block;
	}
	else
	{
		g_heap.start = block;
		g_heap.last = block;
	}
	
	return;
}
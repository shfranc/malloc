#include "malloc.h"

static int		ft_show_heap(t_heap	*heap)
{
	t_block	*block;
	int		total;

	block = heap->start;
	total = 0;
	while (block)
	{
		if (!block->free)
		{
			ft_putaddr((unsigned long long)(block->data));
			ft_putstr(" - ");
			ft_putaddr((unsigned long long)((char*)block->data + block->size));
			ft_putstr(" : ");
			ft_putnbr(block->size);
			ft_putendl(" octets");
			total += block->size;
		}
		block = block->next;
	}
	return total;
}


void			show_alloc_mem(void)
{
	int		total;

	ft_putstr("TINY : ");
	ft_putaddr_endl((unsigned long long)g_handler.tiny.start);
	total = ft_show_heap(&g_handler.tiny);
	
	ft_putstr("SMALL : ");
	ft_putaddr_endl((unsigned long long)g_handler.small.start);
	total += ft_show_heap(&g_handler.small);
	
	ft_putstr("LARGE : ");
	ft_putaddr_endl((unsigned long long)g_handler.large.start);
	total += ft_show_heap(&g_handler.large);
	ft_putnbr_str("Total : ", total);	
}
#include "malloc.h"

static int		ft_show_heap(t_block *blocks)
{
	t_block	*block;
	int		total;
	
	ft_putaddr_endl((unsigned long long int)blocks);
	block = blocks;
	total = 0;
	while (block)
	{
		if (!block->free)
		{
			ft_putaddr((unsigned long long int)(block->data));
			ft_putstr(" - ");
			ft_putaddr((unsigned long long int)((char*)block->data + block->size));
			ft_putstr(" : ");
			ft_putnbr(block->size);
			ft_putendl(" octets");
			total += block->size;
		}
		block = block->next;
	}
	return (total);
}


void			show_alloc_mem(void)
{
	int		total;

	ft_putstr("TINY : ");
	total = ft_show_heap(g_heap.tiny);
	ft_putstr("SMALL : ");
	total += ft_show_heap(g_heap.small);	
	ft_putstr("LARGE : ");
	total += ft_show_heap(g_heap.large);
	ft_putnbr_str("Total : ", total);	
}
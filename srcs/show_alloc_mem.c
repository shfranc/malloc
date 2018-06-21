#include "malloc.h"

void			ft_show_heap(t_block *blocks)
{
	t_block		*block;

	block = blocks;
	while (block)
	{
		ft_putaddr_endl((unsigned long long)block);
		ft_putnbr_str("size:", block->size);
		block = block->next;
	}
}


void			show_alloc_mem(void)
{
	ft_putstr("TINY : ");
	ft_putaddr_endl((unsigned long long)&g_heap[TINY]);
	ft_putstr("\tfree : ");
	ft_putaddr_endl((unsigned long long)g_heap[TINY].free);
	ft_show_heap(g_heap[TINY].free);

	ft_putstr("SMALL : ");
	ft_putaddr_endl((unsigned long long)&g_heap[SMALL]);
	ft_putstr("\tfree : ");
	ft_putaddr_endl((unsigned long long)g_heap[SMALL].free);
	ft_show_heap(g_heap[SMALL].free);

	ft_putstr("LARGE : ");
	ft_putaddr_endl((unsigned long long)&g_heap[LARGE]);
	ft_putstr("\tfree : ");
	ft_putaddr_endl((unsigned long long)g_heap[LARGE].free);
	ft_show_heap(g_heap[LARGE].free);

}
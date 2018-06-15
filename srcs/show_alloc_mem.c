#include "malloc.h"

void	ft_show_heap(t_heap	*heap)
{
	t_block	*block;

	block = heap->start;
	while (block)
	{
		ft_putaddr((unsigned long long)(block->data));
		ft_putstr(" - ");
		ft_putaddr((unsigned long long)((char*)block->data + block->size));
		ft_putstr(" : ");
		ft_putnbr(block->size);
		ft_putendl(" octets");
		block = block->next;
	}
}


void	show_alloc_mem(void)
{
	ft_putstr("TINY : ");
	ft_putaddr_endl((unsigned long long)g_handler.tiny.start);
	ft_show_heap(&g_handler.tiny);
	ft_putstr("SMALL : ");
	ft_putaddr_endl((unsigned long long)g_handler.small.start);
	ft_show_heap(&g_handler.small);
	ft_putstr("LARGE : ");
	ft_putaddr_endl((unsigned long long)g_handler.large.start);
	ft_show_heap(&g_handler.large);
	ft_putnbr_str("Total : ", 0);	
}
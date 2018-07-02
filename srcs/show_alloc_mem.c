#include "malloc.h"

void			ft_show_block(t_block *block)
{
	ft_putaddr((unsigned long long)block);
	ft_putstr(" ** ");		
	ft_putaddr((unsigned long long)((char*)block + ft_header_size()));
	ft_putstr(" - ");
	ft_putaddr((unsigned long long)((char*)block + ft_header_size() + block->size));
	ft_putstr(" : ");
	ft_putnbr(block->size);
	ft_putendl(" octets");
}

void		ft_show_block_full(t_block *block)
{
	ft_putaddr((unsigned long long)block);
	ft_putstr(" ** ");		
	ft_putaddr((unsigned long long)((char*)block + ft_header_size()));
	ft_putstr(" - ");
	ft_putaddr((unsigned long long)((char*)block + ft_header_size() + block->size));
	ft_putstr(" : ");
	ft_putnbr(block->size);
	ft_putstr(" octets -");
	ft_putstr(" prev : ");
	ft_putaddr((unsigned long long)block->prev);
	ft_putstr(" next : ");
	ft_putaddr((unsigned long long)block->next);
	ft_putendl("");
}

void			ft_show_heap(t_block *blocks)
{
	t_block		*block;

	block = blocks;
	while (block)
	{
		ft_show_block(block);
		// ft_show_block_full(block);
		block = block->next;
	}
}


void			show_alloc_mem(void)
{
	ft_putstr("TINY : ");
	ft_putaddr_endl((unsigned long long)&g_heap[TINY]);
	ft_putstr("\tfree : ");
	ft_putaddr_endl((unsigned long long)g_heap[TINY].free);
	ft_list_len(g_heap[TINY].free); //
	ft_show_heap(g_heap[TINY].free);
	ft_putstr("\tin use : ");
	ft_putaddr_endl((unsigned long long)g_heap[TINY].in_use);
	ft_list_len(g_heap[TINY].in_use);
	ft_show_heap(g_heap[TINY].in_use);
	
	ft_putstr("SMALL : ");
	ft_putaddr_endl((unsigned long long)&g_heap[SMALL]);
	ft_putstr("\tfree : ");
	ft_putaddr_endl((unsigned long long)g_heap[SMALL].free);
	ft_list_len(g_heap[SMALL].free);
	ft_show_heap(g_heap[SMALL].free);
	ft_putstr("\tin use : ");
	ft_putaddr_endl((unsigned long long)g_heap[SMALL].in_use);
	ft_list_len(g_heap[SMALL].in_use);
	ft_show_heap(g_heap[SMALL].in_use);

	ft_putstr("LARGE : ");
	ft_putaddr_endl((unsigned long long)&g_heap[LARGE]);
	ft_putstr("\tfree : ");
	ft_putaddr_endl((unsigned long long)g_heap[LARGE].free);
	ft_list_len(g_heap[LARGE].free);
	ft_show_heap(g_heap[LARGE].free);
	ft_putstr("\tin use : ");
	ft_putaddr_endl((unsigned long long)g_heap[LARGE].in_use);
	ft_list_len(g_heap[LARGE].in_use);
	ft_show_heap(g_heap[LARGE].in_use);
}
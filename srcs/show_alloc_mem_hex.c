#include "malloc.h"

void			ft_show_block_hex(t_block *block)
{	
	ft_putaddr((unsigned long long)((char*)block + ft_header_size()));
	ft_putstr(" - ");
	ft_putaddr((unsigned long long)((char*)block + ft_header_size() + block->size));
	ft_putstr(" : ");
	ft_putnbr(block->size);
	ft_putendl(" octets");
	ft_print_memory((void*)block, block->size);
}

void			ft_show_heap_hex(t_block *blocks)
{
	t_block		*block;
	t_block		*last;

	last = NULL;
	block = blocks;
	while (block)
	{
		last = block;
		block = block->next;
	}
	block = last;
	while (block)
	{
		ft_show_block_hex(block);
		block = block->prev;
	}
}

void			show_alloc_mem_hex(void)
{
	pthread_mutex_lock(&g_mutex);
	ft_putstr("TINY : ");
	ft_putaddr_endl((unsigned long long)g_heap[TINY].in_use);
	ft_show_heap_hex(g_heap[TINY].in_use);
	ft_putstr("SMALL : ");
	ft_putaddr_endl((unsigned long long)g_heap[SMALL].in_use);
	ft_show_heap_hex(g_heap[SMALL].in_use);
	ft_putstr("LARGE : ");
	ft_putaddr_endl((unsigned long long)g_heap[LARGE].in_use);
	ft_show_heap_hex(g_heap[LARGE].in_use);
	pthread_mutex_unlock(&g_mutex);
}
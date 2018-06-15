#include "malloc.h"

void	ft_init_block(t_block *block, size_t size)
{
	block->size = size - BLOCK_SIZE;
	block->free = 1;
	block->next = NULL;
	block->data = (char*)block + BLOCK_SIZE;
}

void	*ft_find_block(size_t size)
{
	t_block		*block;

	block = g_heap.start;

	while(block)
	{
		if (block->free && block->size >= size)
		{
			block->next = ft_split_block(block, size);
			if (block->next)
				block->size = size;
			block->free = 0;
			g_heap.mapped += size + BLOCK_SIZE; 
			return block->data;
		}
		block = block->next;
	}
	return NULL;
}

void	*ft_split_block(t_block *last, size_t size)
{
	t_block		*block;

	block = NULL;

	if ((last->size - size) >= TINY)
	{
		block = (t_block*)(last->data + size);
		ft_init_block(block, last->size - size);
		g_heap.last = block;
	}

	return block;
}

void	ft_print_blocks(t_block *blocks)
{
	t_block	*block;
	int		i;

	i = 0;
	block = blocks;
	while (block)
	{
		ft_putstr(BLUE);
		ft_putnbr_str("BLOCK: ", ++i);
		ft_putaddr((unsigned long long)(block));
		ft_putstr(RESET);
		ft_putnbr_str("offset: ", (int)((char*)block - (char*)g_heap.start));
		ft_putnbr_str("size: ", block->size);
		ft_putnbr_str("free: ", block->free);
		ft_putstr("next: ");
		ft_putaddr((unsigned long long)(block->next));
		ft_putstr("data: ");
		ft_putaddr((unsigned long long)(block->data));
		block = block->next;
	}
}
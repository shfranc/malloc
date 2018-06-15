#include "malloc.h"

void	ft_init_block(t_block *block, size_t size)
{
	block->size = size - BLOCK_SIZE;
	block->free = 1;
	block->next = NULL;
	block->data = (char*)block + BLOCK_SIZE;
}

void	*ft_find_block(t_heap *heap, size_t size)
{
	t_block		*block;

	block = heap->start;

	while(block)
	{
		if (block->free && block->size >= size)
		{
			block->next = ft_split_block(heap, block, size);
			if (block->next)
				block->size = size;
			block->free = 0;
			heap->mapped += size + BLOCK_SIZE; 
			return block->data;
		}
		block = block->next;
	}
	return NULL;
}

void	*ft_split_block(t_heap *heap, t_block *last, size_t size)
{
	t_block		*block;

	block = NULL;

	if ((last->size - size) >= TINY) // trouver un moyen de rendre ça général...
	{
		block = (t_block*)(last->data + size); // pas de cast en char* pour ça ??
		ft_init_block(block, last->size - size);
		heap->last = block;
	}

	return block;
}

int		ft_fusion_block(t_heap *heap, t_block *block1, t_block *block2)
{
	if (block1->free && block2->free)
	{
		ft_putstr("block1->data + block1->size: ");
		ft_putaddr_endl((unsigned long long)((char*)block1->data + block1->size));
		ft_putstr("block2: ");
		ft_putaddr_endl((unsigned long long)block2);
		if ( (unsigned long long)((char*)block1->data + block1->size) == (unsigned long long)block2 )
		{
			ft_putendl("FUSION !!!");
			block1->size += block2->size;
			heap->mapped -= BLOCK_SIZE;
			return 1;
		}
	}
	return 0;
}

void	ft_print_blocks(t_heap *heap)
{
	t_block	*block;
	int		i;

	i = 0;
	block = heap->start;
	while (block)
	{
		ft_putstr(BLUE);
		ft_putnbr_str("BLOCK: ", ++i);
		ft_putaddr_endl((unsigned long long)block);
		ft_putstr(RESET);
		ft_putnbr_str("offset: ", (int)((char*)block - (char*)heap->start));
		ft_putnbr_str("size: ", block->size);
		ft_putnbr_str("free: ", block->free);
		ft_putstr("next: ");
		ft_putaddr_endl((unsigned long long)(block->next));
		ft_putstr("data: ");
		ft_putaddr_endl((unsigned long long)(block->data));
		block = block->next;
	}
	ft_putendl("---------------------------------");
}
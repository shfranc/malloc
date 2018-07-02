#include "malloc.h"

void	ft_fusion_blocks(t_block *block1, t_block *block2)
{
	// ft_putstr("ft_fusion_blocks: ");
	// ft_putaddr((unsigned long long)block1);
	// ft_putstr(" and ");
	// ft_putaddr_endl((unsigned long long)block2);

	block1->size += block2->size + ft_header_size();
	block1->next = block2->next;
	if (block2->next)
		block2->next->prev = block1;
}

void	ft_defragmentation(int type)
{
	t_block		*block;

	block = g_heap[type].free;
	while (block)
	{
		if (block->next && (char*)block->next == ((char*)block + ft_header_size() + block->size))
		{
			ft_fusion_blocks(block, block->next);
			STAT ? ft_stat_defrag() : 0;
			// ft_putstr("ft_fusion_blocks: ");
			// ft_show_block_full(block);
		}
		else
			block = block->next;
	}
}
#include "malloc.h"

void		ft_fusion_blocks(t_block *block1, t_block *block2)
{
	ft_putendl(WHITE"FUSION !!"RESET);
	block1->size += block2->size + ft_header_size();
	block1->next = block2->next;
	if (block2->next)
		block2->next->prev = block1;
}

// void	ft_defragmentation(int type)
// {
// 	t_block		*block;

// 	block = g_heap[type].free;
// 	while (block)
// 	{
// 		if (block->next && (char*)block->next == ((char*)block + ft_header_size() + block->size))
// 		{
// 			ft_fusion_blocks(block, block->next);
// 		}
// 		else
// 			block = block->next;
// 	}
// }
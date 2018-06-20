#include "malloc.h"

size_t		ft_header_size(void)
{
	return sizeof(t_block);
}

void	ft_move_block_to_use(int type, t_block *block)
{
	(void)type;
	(void)block;
	// suppr from free list
	if (block->prev)
		block->prev->next = block->next;
	if (block->next)
		block->next->prev = block->prev;

	// add to in_use
	if (!g_heap[type].in_use)
		g_heap[type].in_use = block;
	else
	{
		g_heap[type].in_use->prev = block;
		block->prev = NULL;
		block->next = g_heap[type].in_use;
	}

}

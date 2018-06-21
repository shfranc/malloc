#include "malloc.h"

size_t		ft_header_size(void)
{
	return sizeof(t_block);
}

void	ft_move_block_to_use(int type, t_block *block)
{
	// suppr from free list
	if (block->prev)
		block->prev->next = block->next;
	else
		g_heap[type].free = block->next;

	if (block->next)
		block->next->prev = block->prev;

	ft_putendl("--- free");
	ft_show_heap(g_heap[type].free);
	ft_putendl("--- free");

	// add to in_use
	if (!g_heap[type].in_use)
	{
		ft_putendl("in_use is empty");
		g_heap[type].in_use = block;
		block->next = NULL;
		block->prev = NULL;
	}
	else
	{
		ft_putendl("in_use is not empty");

		g_heap[type].in_use->prev = block;
		block->next = g_heap[type].in_use;
		block->prev = NULL;
		g_heap[type].in_use = block;
	}

	ft_putendl("--- in use");
	ft_show_heap(g_heap[type].in_use);
	ft_putendl("--- in use");

}

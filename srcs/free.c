#include "malloc.h"

void	free(void *ptr)
{
	t_block		*block;
	int			type;

	g_debug ? ft_putendl("\n\t\tFREE") : 0;

	block = NULL;
	if (!ptr)
	{
		g_debug ? ft_putendl("free - trying to free a NULL ptr") : 0;
		return ;
	}
	
	type = ft_find_used_block(ptr, &block);
	
	// if (block && (type == TINY || type == SMALL))
	if (block)
	{
		ft_move_block_to_free(type, block);
		// ft_defragmentation(type);
	}
	
	g_debug ? ft_print_debug(2, block) : 0;
	g_debug ? show_alloc_mem() : 0;
}
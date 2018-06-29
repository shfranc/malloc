#include "malloc.h"

void	ft_munmap_large(t_block *block)
{
	munmap(block, block->size + ft_header_size());
}

void	ft_free_block(int type, t_block *block)
{
	// if (!block)
		// return ;
	if (type == TINY || type == SMALL)			
	{
		ft_move_block_to_free(type, block);
		ft_defragmentation(type);
	}
	else if (type == LARGE)
		ft_munmap_large(block);
}

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
	
	if (type != -1)
		ft_free_block(type, block);

	// if (block && (type == TINY || type == SMALL))
	// if (block)
	// {
	// 	ft_move_block_to_free(type, block);
	// 	ft_defragmentation(type);
	// }
	
	g_debug ? ft_print_debug(2, block) : 0;
	g_debug ? show_alloc_mem() : 0;
}
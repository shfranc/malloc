#include "malloc.h"

void	free(void *ptr)
{
	t_block		*block;
	int			type;

	ft_putendl("\t\tFREE");

	block = NULL;
	if (!ptr)
	{
		ft_putendl("free - trying to free a NULL ptr");
		return ;
	}
	
	type = ft_find_used_block(ptr, &block);
	
	// if (block && (type == TINY || type == SMALL))
	if (block)
	{
		ft_move_block_to_free(type, block);
		ft_defragmentation(type);
	}
	
	ft_print_debug(2, block);
	// show_alloc_mem();
}
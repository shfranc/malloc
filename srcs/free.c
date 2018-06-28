#include "malloc.h"

void	free(void *ptr)
{
	t_block		*block;
	int			type;
	int			defrag;

	block = NULL;
	defrag = 0;
	ft_putendl(RED"FREE"RESET);
	ft_print_debug(2, ptr, 0);

	if (!ptr)
	{
		ft_putendl("trying to free a NULL ptr");
		return ;
	}
	
	type = ft_find_used_block(ptr, &block);
	
	// if (block && (type == TINY || type == SMALL))
	if (block)
	{

		defrag = ft_move_block_to_free(type, block);
		ft_defragmentation(type);
	}

}
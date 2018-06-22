#include "malloc.h"

void	free(void *ptr)
{
	t_block		*block;
	int			type;
	int			defrag;

	block = NULL;
	defrag = 0;
	ft_putendl(RED"FREE"RESET);
	
	type = ft_find_used_block(ptr, &block);
	
	// if (block && (type == TINY || type == SMALL))
	if (block)
		defrag = ft_move_block_to_free(type, block);

	if (defrag)
		ft_defragmentation(type);

}
#include "malloc.h"

void	free(void *ptr)
{
	t_block		*block;
	int			type;

	block = NULL;
	ft_putendl(RED"FREE"RESET);

	if (!ptr)
	{
		ft_print_debug(2, ptr, 0);
		ft_putendl("trying to free a NULL ptr");
		return ;
	}
	
	type = ft_find_used_block(ptr, &block);
	
	// if (block && (type == TINY || type == SMALL))
	if (block)
	{
		ft_print_debug(2, (char*)block + ft_header_size(), block->size);
		ft_move_block_to_free(type, block);
		ft_defragmentation(type);
	}

}
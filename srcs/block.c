#include "malloc.h"

size_t		ft_header_size(void)
{
	return sizeof(t_block);
}

void	ft_move_block_to_use(int type, t_block *block)
{
	(void)type;
	(void)block;



}

#include "malloc.h"

size_t		ft_header_size(void)
{
	return ft_align_size(sizeof(t_block), 16);
}

static int		ft_get_min_size(int type)
{
	return (type == TINY ? TINY_BLOCK : SMALL_BLOCK);
}

t_block		*ft_split_block(t_block *block, int type, size_t size)
{
	t_block		*new_block;
	int			min_size;

	min_size = ft_get_min_size(type);
	if ((block->size - size) >= (min_size + ft_header_size()))
	{
		new_block = (t_block*)((char*)block + ft_header_size() + size);
		new_block->size = block->size - size - ft_header_size();
		new_block->prev = block;
		new_block->next = block->next;

		block->next = new_block;
		if (block->next)
			block->next->prev = new_block;
		block->size = size;
		ft_putnbr_str(YELLOW"block splitted:"RESET, new_block->size);
		return (new_block);
	}
	ft_putnbr_str(YELLOW"block NOT splitted:"RESET, block->size);
	return (block->next);
}

void		ft_delete_block(t_block **start, t_block *block)
{
	if (block->prev)
		block->prev->next = block->next;
	else
		*start = block->next;

	if (block->next)
		block->next->prev = block->prev;
}

void		ft_insert_block_top(t_block **start, t_block *block)
{
	ft_putendl(GREEN"add TOP"RESET);
	if (!*start)
	{
		*start = block;
		block->next = NULL;
		block->prev = NULL;
	}
	else
	{
		(*start)->prev = block;
		block->next = *start;
		block->prev = NULL;
		*start = block;
	}
}

void		ft_insert_block_top_defrag(t_block **start, t_block *block)
{
	ft_putendl(GREEN"add TOP"RESET);
	if (!*start)
	{
		*start = block;
		block->next = NULL;
		block->prev = NULL;
	}
	else
	{
		(*start)->prev = block;
		block->next = *start;
		block->prev = NULL;
		*start = block;
		ft_fusion_blocks(*start, block);
	}
}

// int		ft_insert_block_addr(t_block **start, t_block *new_block) // after
// {
// 	t_block		*block;

// 	if (!*start)
// 	{
// 		ft_putendl(GREEN"free is empty"RESET);
// 		*start = new_block;
// 		new_block->next = NULL;
// 		new_block->prev = NULL;
// 		return (1);
// 	}
// 	else
// 	{
// 		block = *start;
// 		while (block)
// 		{
// 			// ft_putendl("looking for a place..");
// 			if ((char*)new_block == ((char*)block + ft_header_size() + block->size))
// 			{
// 				ft_putendl(PINK"add PERFECT place"RESET);
// 				new_block->next = block->next;
// 				if (block->next)
// 					block->next->prev = new_block;
// 				block->next = new_block;
// 				new_block->prev = block;
// 				ft_fusion_blocks(block, new_block);
// 				return (1);
// 			}
// 			block = block->next;
// 		}
// 	}
// 	return (0);
// }

int		ft_insert_block_addr(t_block **start, t_block *new_block) // before
{
	t_block		*block;

	if (!*start)
	{
		ft_putendl(GREEN"free is empty"RESET);
		*start = new_block;
		new_block->next = NULL;
		new_block->prev = NULL;
		return (1);
	}
	else
	{
		block = *start;
		while (block)
		{
			// ft_putendl("looking for a place..");
			if (((char*)new_block + ft_header_size() + new_block->size) == (char*)block)
			{
				ft_putendl(PINK"insert before"RESET);
				new_block->prev = block->prev;				
				new_block->next = block;
				if (block->prev) // utile ?
					block->prev->next = new_block;
				else
					*start =  new_block;
				block->prev = new_block;
				ft_fusion_blocks(new_block, block);
				return (1);
			}
			block = block->next;
		}
	}
	return (0);
}

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
		block->size = size;
		ft_putnbr_str("ft_split_block: block splitted:", new_block->size);
		return (new_block);
	}
	ft_putnbr_str("ft_split_block: block NOT splitted:", block->size);
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
	if (!*start)
	{
		ft_putendl("ft_insert_block_top: empty list ");
		*start = block;
		block->next = NULL;
		block->prev = NULL;
	}
	else
	{
		ft_putendl("ft_insert_block_top: new top of the list ");
		ft_list_len(*start);
		(*start)->prev = block;
		block->next = *start;
		block->prev = NULL;
		*start = block;
		ft_list_len(*start);
	}
}

int		ft_insert_block_addr(t_block **start, t_block *new_block)
{
	t_block		*block;
	int i;

	i = 0;

	if (!*start)
	{
		ft_putendl("ft_insert_block_addr: free is empty");
		*start = new_block;
		new_block->next = NULL;
		new_block->prev = NULL;
		return (1);
	}
	else
	{
		block = *start;
		i = 0;
		while (block)
		{
			i++;
			// ft_putendl("looking for a place..");
			if ((char*)new_block == ((char*)block + ft_header_size() + block->size))
			{
				ft_putnbr_str("ft_insert_block_addr: add PERFECT place ", i);
				new_block->next = block->next;
				if (block->next)
					block->next->prev = block;
				block->next = new_block;
				return (1);
			}
			block = block->next;
		}
	}
	return (0);
}

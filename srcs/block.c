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

		block->size = size;
		if (block->next)
			block->next->prev = new_block;
		block->next = new_block;

		g_debug ? ft_putnbr_str("ft_split_block: block splitted:", new_block->size) : 0;
		g_debug ? ft_putstr("block: ") : 0;
		g_debug ? ft_show_block_full(block) : 0;
		g_debug ? ft_putstr("new_block: ") : 0;
		g_debug ? ft_show_block_full(new_block) : 0;
		g_debug && new_block->next ? ft_show_block_full(new_block->next) : 0;
		return (new_block);
	}
	g_debug ? ft_putnbr_str("ft_split_block: block NOT splitted:", block->size) : 0; // c'est la mierda ici
	g_debug ? ft_putaddr_endl((unsigned long long)block->next): 0;
	return (block->next);
}

void		ft_delete_block(t_block **start, t_block *block)
{

	// ft_putendl("ft_delete_block: is HEAD");

	// ft_putendl("ft_delete_block: is TAIL");

	// ft_putendl("ft_delete_block: is MIDDLE");



	if (block->next)
		block->next->prev = block->prev;

	if (block->prev)
		block->prev->next = block->next;
	
	if (*start == block)
		*start = block->next;

}

void		ft_insert_block_top(t_block **start, t_block *block)
{
	// t_block *right;

	if (!*start)
	{
		g_debug ? ft_putendl("ft_insert_block_top: empty list ") : 0;
		*start = block;
		block->next = NULL;
		block->prev = NULL;
	}
	else
	{
		g_debug ? ft_putendl("ft_insert_block_top: new top of the list ") : 0;
		g_debug ? ft_list_len(*start) : 0;


		// right = *start;
		// *start = block;
		// block->prev = NULL;
		// block->next = right;
		// right->prev = block;

		// (*start)->prev = block;
		// block->next = *start;
		// block->prev = NULL;
		// *start = block;
		
		block->next = *start;
		block->prev = NULL;
		(*start)->prev = block;
		*start = block;

		g_debug ? ft_list_len(*start) : 0;
	}
}

int		ft_insert_block_addr(t_block **start, t_block *new_block)
{
	t_block		*block;
	int i;

	i = 0;

	if (!*start)
	{
		g_debug ? ft_putendl("ft_insert_block_addr: free is empty") : 0;
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
				g_debug ? ft_putnbr_str("ft_insert_block_addr: add PERFECT place ", i) : 0;
				
				new_block->next = block->next;
				new_block->prev = block;
				
				if (block->next)
				{
					g_debug ? ft_putendl("modif block->next->prev") : 0;
					block->next->prev = new_block;
				}

				block->next = new_block;

				return (1);
			}
			block = block->next;
		}
	}
	return (0);
}

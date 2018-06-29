#include "malloc.h"
#include <string.h>

static void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *temp_dst;
	unsigned char *temp_src;

	temp_dst = (unsigned char*)dst;
	temp_src = (unsigned char*)src;
	if (dst <= src)
	{
		while (n-- > 0)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		temp_src = temp_src + n - 1;
		temp_dst = temp_dst + n - 1;
		while (n-- > 0)
			*temp_dst-- = *temp_src--;
	}
	return (dst);
}

static void		*ft_do_realloc(int type, t_block *block, size_t size)
{
	void	*new_data;

	new_data = malloc(size);
	ft_memmove(new_data, (char*)block + ft_header_size(), ft_align_size(size, 16));
	ft_move_block_to_free(type, block);
	
	g_debug ? ft_print_debug(3, block) : 0;

	return (new_data);
}

void		*realloc(void *ptr, size_t size)
{
	t_block		*block;
	int			type;

	// show_alloc_mem();
	g_debug ? ft_putendl("\n\t\tREALLOC") : 0;

	if (!ptr)
	{
		g_debug ? ft_putnbr_str("realloc - ptr NULL --> malloc - size", size) : 0;
		return (malloc(size));
	}

	type = ft_find_used_block(ptr, &block);
	if (type == -1 || !block)
	{
		g_debug ? ft_putendl("realloc - ptr not found --> NULL") : 0;
		return (NULL);
	}

	if (size <= block->size)
	{
		g_debug ? ft_putendl("realloc - size is smaller --> ptr") : 0;
		return (ptr);
	}
	else
	{
		g_debug ? ft_putendl("do realloc !!") : 0;
		return (ft_do_realloc(type, block, size));
	}

	return (NULL);
}
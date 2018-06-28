#include "malloc.h"

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

	(void)type;

	new_data = malloc(size);
	ft_memmove(new_data, (char*)block + ft_header_size(), size);
	ft_move_block_to_free(type, block);
	ft_putaddr_endl((unsigned long long)new_data);
	return (new_data);
}

void		*realloc(void *ptr, size_t size)
{
	t_block		*block;
	int			type;

	ft_putendl(CYAN"REALLOC"RESET);
	ft_print_debug(3, ptr, size);

	if (!ptr)
	{
		ft_putendl("realloc - ptr NULL --> malloc");
		return (malloc(size));
	}

	type = ft_find_used_block(ptr, &block);
	if (type == -1)
	{
		ft_putendl("realloc - ptr not found --> NULL");
		return (NULL);
	}

	ft_putnbr_str("block size", block->size);
	ft_putnbr_str("new size", size);
	
	if (size <= block->size)
	{
		ft_putendl("realloc - size is smaller --> ptr");
		return (ptr);
	}
	else
	{
		ft_putendl("do realloc !!");
		return (ft_do_realloc(type, block, size));
	}

	return (NULL);
}
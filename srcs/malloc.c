#include "malloc.h"

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

t_block		*ft_alloc_large(size_t size)
{
	t_block 	*block;
	size_t		pages;

	pages = ft_align_size(size + ft_header_size(), getpagesize());
	block = ft_request_memory(NULL, pages);
	block->size = pages - ft_header_size();
	block->prev = NULL;
	block->next = NULL;
	ft_insert_block_top(&g_heap[LARGE].in_use, block);
	return (block);
}

static int		ft_choose_pool(size_t size)
{
	if (size <= TINY_BLOCK)
		return (TINY);
	else if (size <= SMALL_BLOCK)
		return (SMALL);
	else
		return (LARGE);
}

void	*malloc(size_t size)
{
	unsigned int	type;
	t_block			*block;

	pthread_mutex_lock(&g_mutex);
	size = ft_align_size(size, 16);
	type = ft_choose_pool(size);
	if (type == TINY || type == SMALL)
	{
		block = ft_choose_free_block(type, size);
		if (!block)
			return (NULL);
		block->next = ft_split_block(block, type, size);
		ft_move_block_to_use(type, block);
	}
	else
		block = ft_alloc_large(size);
	LOG ? ft_log(MALLOC, block) : 0;
	pthread_mutex_unlock(&g_mutex);
	return ((void*)((char*)block + ft_header_size()));
}

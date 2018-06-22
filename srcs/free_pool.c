#include "malloc.h"

int		ft_choose_pool(size_t size)
{
	if (size <= TINY_BLOCK)
		return (TINY);
	else if (size <= SMALL_BLOCK)
		return (SMALL);
	else
		return (LARGE);
}

t_block		*ft_choose_free_block(int type, size_t size)
{
	t_block		*block;
	t_block		*last;

	block = g_heap[type].free;
	while (block)
	{
		last = block;
		if (block->size >= size)
			return (block);
		block = block->next;
	}

	if (!block) // useless ?? Non, les tous les block sont0 trop petits !
	{
		ft_putendl("extend heap ICI - size not big enough");
		last->next = ft_extend_free_pool(last, type, size);
	}

	return (last->next); // 
}

t_block		*ft_extend_free_pool(void *last, int type, size_t size)
{
	t_block 	*block;
	size_t		pages;


	if (type == TINY)
		pages = ft_align_size(NB_BLOCKS * (TINY_BLOCK + ft_header_size()), getpagesize());
	else if (type == SMALL)
		pages = ft_align_size(NB_BLOCKS * (SMALL_BLOCK + ft_header_size()), getpagesize());		
	else
		pages = ft_align_size(size + ft_header_size(), getpagesize());

	block = ft_request_memory(last + ft_header_size(), pages);
	block->size = pages - ft_header_size();
	block->prev = last;
	block->next = NULL;
	ft_putnbr_str(YELLOW"extend heap:"RESET, block->size);

	return(block);
}

t_block		*ft_request_memory(void *last, size_t size)
{
	return (mmap(last, size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0));
}

void		ft_move_block_to_use(int type, t_block *block)
{
	ft_delete_block(&g_heap[type].free, block);
	ft_insert_block_top(&g_heap[type].in_use, block);
}

void	ft_defragmentation(int type)
{
	t_block		*block;

	block = g_heap[type].free;
	while (block)
	{
		if (block->next && (char*)block->next == ((char*)block + ft_header_size() + block->size))
		{
			ft_fusion_blocks(block, block->next);
		}
		else
			block = block->next;
	}
}
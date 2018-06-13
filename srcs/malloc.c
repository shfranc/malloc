#include "malloc.h"

void	ft_print_blocks(t_block *blocks)
{
	t_block	*block;

	block = blocks;
//	while (block)
//	{
		ft_putnbr_str("size: ", block->size);
		ft_putstr("next: ");
		ft_putaddr((unsigned long long)(block->next));
		ft_putstr("data: ");
		ft_putaddr((unsigned long long)(block->data));
		block = block->next;
//	}
}

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	*malloc(size_t size)
{
	char		*ret;
	t_block		*block;

	block = (t_block*)mmap(0, sizeof(t_block), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	block->size = size;
	block->next = NULL;
	block->free = 0;

	ret = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	block->data = ret;

	ft_print_blocks(block);
	
	return ret;
}

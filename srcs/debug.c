#include "malloc.h"

static void	ft_print_debug_line(char *s, t_block *block)
{
	// ft_putstr_fd(2, s);
	// ft_putstr_fd(2, " - ");
	// ft_putaddr_fd(2, (unsigned long long)ptr);
	// ft_putstr_fd(2, " - ");
	// ft_putnbr_fd(2, size);
	// ft_putstr_fd(2, " octets");
	// ft_putchar_fd(2, '\n');

	ft_putstr_fd(2, s);
	ft_putstr_fd(2, "\t- ");
	ft_putaddr_fd(2, (unsigned long long)block);
	if (block)
	{
		ft_putstr_fd(2, " ** ");		
		ft_putaddr_fd(2, (unsigned long long)((char*)block + ft_header_size()));
		ft_putstr_fd(2, " - ");
		ft_putaddr_fd(2, (unsigned long long)((char*)block + ft_header_size() + block->size));
		ft_putstr_fd(2, " : ");
		ft_putnbr_fd(2, block->size);
		ft_putstr_fd(2, " octets -");
		ft_putstr_fd(2, " prev : ");
		ft_putaddr_fd(2, (unsigned long long)block->prev);
		ft_putstr_fd(2, " next : ");
		ft_putaddr_fd(2, (unsigned long long)block->next);
	}
	ft_putchar_fd(2, '\n');
}

void	ft_print_debug(int func, t_block *block)
{
	if (func == 1)
		ft_print_debug_line("malloc", block);
	else if (func == 2)
		ft_print_debug_line("free", block);
	else if (func == 3)
		ft_print_debug_line("realloc", block);
	else if (func == 4)
		ft_print_debug_line("calloc", block);	
}

void	ft_list_len(t_block *blocks)
{
	t_block		*block;
	int			i;

	i = 0;
	block = blocks;
	while(block)
	{
		i++;
		block = block->next;
	}
	ft_putnbr_str("len heap", i);
}

void	ft_print_pool(int type)
{
	if (type == 0)
		ft_putstr("-- TINY ");
	else if (type == 1)
		ft_putstr("-- SMALL ");
	else if (type == 2)
		ft_putstr("-- LARGE ");
}
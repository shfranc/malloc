#include "malloc.h"

static void	ft_print_log_line(char *s, t_block *block)
{
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

void	ft_log(int f, t_block *block)
{
	if (f == REALLOC)
		ft_putstr_fd(2, "realloc: ");
	else if (f == CALLOC)
		ft_putstr_fd(2, "calloc: ");
	else if (f == MALLOC)
		ft_print_log_line("malloc", block);
	else if (f == FREE)
		ft_print_log_line("free", block);	
}
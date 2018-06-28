#include "malloc.h"

static void	ft_print_debug_line(char *s, void *ptr, size_t size)
{
	ft_putstr_fd(2, s);
	ft_putstr_fd(2, " - ");
	ft_putaddr_fd(2, (unsigned long long)ptr);
	ft_putstr_fd(2, " - ");
	ft_putnbr_fd(2, size);
	ft_putstr_fd(2, " octets");
	ft_putchar_fd(2, '\n');
}

void	ft_print_debug(int func, void *ptr, size_t size)
{
	if (func == 1)
		ft_print_debug_line("malloc", ptr, size);
	else if (func == 2)
		ft_print_debug_line("free", ptr, size);
	else if (func == 3)
		ft_print_debug_line("realloc", ptr, size);
	else if (func == 4)
		ft_print_debug_line("calloc", ptr, size);	
}
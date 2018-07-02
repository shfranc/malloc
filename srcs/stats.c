#include "malloc.h"

void	ft_stat_malloc(int i)
{
	ft_putstr_fd(2, "malloc ");
	ft_putnbr_fd(2, i);
	ft_putstr_fd(2, "\n");
}

void	ft_stat_free(int i, int len)
{
	ft_putstr_fd(2, "free ");
	ft_putnbr_fd(2, i);
	ft_putstr_fd(2, " ");
	ft_putnbr_fd(2, len);
	ft_putstr_fd(2, "\n");
}

void	ft_stat_defrag(void)
{
	ft_putstr_fd(2, "defrag\n");
}
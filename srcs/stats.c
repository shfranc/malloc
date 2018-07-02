#include "malloc.h"

void	ft_stat_malloc(int i)
{
	ft_putstr_fd(2, "malloc ");
	ft_putnbr_fd(2, i);
	ft_putstr_fd(2, "\n");
}

void	ft_stat_free(void)
{
	ft_putstr_fd(2, "free ");
	ft_putnbr_fd(2, ft_block_len(g_heap[LARGE].free) + ft_block_len(g_heap[SMALL].free) + ft_block_len(g_heap[TINY].free));
	ft_putstr_fd(2, "\n");
}

void	ft_stat_defrag(void)
{
	ft_putstr_fd(2, "defrag\n");
}
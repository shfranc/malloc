#include "malloc.h"
#include <stdio.h>

int		ft_mode_stat(void)
{
	char	*stat;

	if (g_heap[TINY].mode & GETENV)
	{
		return ((g_heap[TINY].mode & STAT) ? 1 : 0);
	}
	if ((stat = getenv(STAT_ENV)) != NULL)
	{
		g_heap[TINY].mode |= GETENV;
		if (stat[0] == '1')
		{
			g_heap[TINY].mode |= STAT;
			return (1);
		}
	}
	else
		g_heap[TINY].mode |= GETENV;
	return (0);
}

void	ft_stat_malloc(int i)
{
	int	fd;

	fd = open(STAT_FILE, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	ft_putstr_fd(fd, "malloc ");
	ft_putnbr_fd(fd, i);
	ft_putstr_fd(fd, "\n");
	close(fd);
}

void	ft_stat_free(void)
{
	int	fd;

	fd = open(STAT_FILE, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	ft_putstr_fd(fd, "free\n");
	close(fd);
}

void	ft_stat_defrag(void)
{
	int	fd;

	fd = open(STAT_FILE, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	ft_putstr_fd(fd, "defrag\n");
	close(fd);
}
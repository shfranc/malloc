#include "malloc.h"
#include <stdio.h>

void	ft_stat_malloc(int i)
{
	int	fd;

	fd = open(STAT_FILE, O_WRONLY | O_APPEND | O_CREAT, S_IWUSR | S_IRGRP | S_IROTH);
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

	fd = open(STAT_FILE, O_WRONLY | O_APPEND | O_CREAT, S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	ft_putstr_fd(fd, "free\n");
	close(fd);
}

void	ft_stat_defrag(void)
{
	int	fd;

	fd = open(STAT_FILE, O_WRONLY | O_APPEND | O_CREAT, S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	ft_putstr_fd(fd, "defrag\n");
	close(fd);
}
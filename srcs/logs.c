/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:35:11 by sfranc            #+#    #+#             */
/*   Updated: 2018/07/05 18:07:12 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			ft_mode_log(void)
{
	char	*log;

	if (g_heap[TINY].mode & GETENV_LOG)
	{
		return ((g_heap[TINY].mode & LOG) ? 1 : 0);
	}
	if ((log = getenv(LOG_ENV)) != NULL)
	{
		g_heap[TINY].mode |= GETENV_LOG;
		if (log[0] == '1')
		{
			g_heap[TINY].mode |= LOG;
			return (1);
		}
	}
	else
		g_heap[TINY].mode |= GETENV_LOG;
	return (0);
}

static void	ft_print_log_line(int fd, char *s, t_block *block)
{
	ft_putstr_fd(fd, s);
	ft_putstr_fd(fd, "\t- ");
	ft_putaddr_fd(fd, (unsigned long long)block);
	if (block)
	{
		ft_putstr_fd(fd, " ** ");
		ft_putaddr_fd(fd, (unsigned long long)((char*)block\
			+ ft_header_size()));
		ft_putstr_fd(fd, " - ");
		ft_putaddr_fd(fd, (unsigned long long)((char*)block\
			+ ft_header_size() + block->size));
		ft_putstr_fd(fd, " : ");
		ft_putnbr_fd(fd, block->size);
		ft_putstr_fd(fd, " octets -");
		ft_putstr_fd(fd, " prev : ");
		ft_putaddr_fd(fd, (unsigned long long)block->prev);
		ft_putstr_fd(fd, " next : ");
		ft_putaddr_fd(fd, (unsigned long long)block->next);
	}
	ft_putchar_fd(fd, '\n');
}

void		ft_log(int f, t_block *block)
{
	int	fd;

	fd = open(LOG_FILE, O_RDWR | O_APPEND | O_CREAT,\
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return ;
	if (f == REALLOC)
		ft_putstr_fd(fd, "realloc: ");
	else if (f == CALLOC)
		ft_putstr_fd(fd, "calloc: ");
	else if (f == MALLOC)
		ft_print_log_line(fd, "malloc", block);
	else if (f == FREE)
		ft_print_log_line(fd, "free", block);
	close(fd);
}

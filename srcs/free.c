/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:35:11 by sfranc            #+#    #+#             */
/*   Updated: 2018/07/05 17:55:05 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		ft_munmap_large(t_block *block)
{
	if ((munmap(block, block->size + ft_header_size())) != 0)
		ft_putstr_fd(2, "munmap error\n");
}

void			ft_free_block(int type, t_block *block)
{
	pthread_mutex_lock(&g_mutex);
	ft_mode_stat() ? ft_stat_free() : 0;
	ft_mode_log() ? ft_log(FREE, block) : 0;
	if (type == TINY || type == SMALL)
	{
		ft_move_block_to_free(type, block);
		ft_defragmentation(type);
	}
	else if (type == LARGE)
	{
		ft_delete_block(&g_heap[LARGE].in_use, block);
		ft_munmap_large(block);
	}
	pthread_mutex_unlock(&g_mutex);
}

void			free(void *ptr)
{
	t_block		*block;
	int			type;

	block = NULL;
	if (!ptr)
		return ;
	pthread_mutex_lock(&g_mutex);
	type = ft_find_used_block(ptr, &block);
	pthread_mutex_unlock(&g_mutex);
	if (type > -1)
		ft_free_block(type, block);
}

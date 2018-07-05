/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_use_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:35:11 by sfranc            #+#    #+#             */
/*   Updated: 2018/07/05 18:06:14 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_block		*ft_search_heap(t_block *blocks, void *ptr, int *i)
{
	t_block		*block;

	block = blocks;
	while (block)
	{
		if ((char*)block + ft_header_size() == (char*)ptr)
			return (block);
		*i += 1;
		block = block->next;
	}
	return (NULL);
}

int					ft_find_used_block(void *ptr, t_block **block)
{
	int		i;

	i = 0;
	if ((*block = ft_search_heap(g_heap[LARGE].in_use, ptr, &i)))
		return (LARGE);
	else if ((*block = ft_search_heap(g_heap[SMALL].in_use, ptr, &i)))
		return (SMALL);
	else if ((*block = ft_search_heap(g_heap[TINY].in_use, ptr, &i)))
		return (TINY);
	return (-1);
}

void				ft_move_block_to_free(int type, t_block *block)
{
	ft_delete_block(&g_heap[type].in_use, block);
	if (!ft_insert_block_addr(&g_heap[type].free, block))
		ft_insert_block_top(&g_heap[type].free, block);
}

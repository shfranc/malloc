/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defragmentation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:52:32 by sfranc            #+#    #+#             */
/*   Updated: 2018/07/05 17:53:44 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		ft_fusion_blocks(t_block *block1,\
	t_block *block2)
{
	block1->size += block2->size + ft_header_size();
	block1->next = block2->next;
	if (block2->next)
		block2->next->prev = block1;
}

void			ft_defragmentation(int type)
{
	t_block		*block;

	block = g_heap[type].free;
	while (block)
	{
		if (block->next && (char*)block->next\
			== ((char*)block + ft_header_size() + block->size))
		{
			ft_fusion_blocks(block, block->next);
			ft_mode_stat() ? ft_stat_defrag() : 0;
		}
		else
			block = block->next;
	}
}

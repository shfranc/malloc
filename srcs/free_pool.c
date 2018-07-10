/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 17:57:15 by sfranc            #+#    #+#             */
/*   Updated: 2018/07/10 10:45:16 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block			*ft_choose_free_block(int type, size_t size)
{
	t_block		*block;
	t_block		*last;
	int			i;

	i = 0;
	block = g_heap[type].free;
	last = NULL;
	while (block)
	{
		i++;
		last = block;
		if (block->size >= size)
		{
			ft_mode_stat() ? ft_stat_malloc(i) : 0;
			return (block);
		}
		block = block->next;
	}
	ft_mode_stat() ? ft_stat_malloc(++i) : 0;
	return (ft_add_free_block(last, type, size));
}

t_block			*ft_add_free_block(t_block *last, int type, size_t size)
{
	if (last)
	{
		last->next = ft_extend_free_pool(last, type, size);
		return (last->next);
	}
	else
	{
		g_heap[type].free = ft_extend_free_pool(last, type, size);
		return (g_heap[type].free);
	}
}

t_block			*ft_extend_free_pool(void *last, int type, size_t size)
{
	t_block		*block;
	size_t		pages;

	if (type == TINY)
	{
		pages = ft_align_size((TINY_BLOCK + ft_header_size() * NB_BLOCKS),\
			getpagesize());
	}
	else if (type == SMALL)
	{
		pages = ft_align_size((SMALL_BLOCK + ft_header_size() * NB_BLOCKS),\
			getpagesize());
	}
	else
		pages = ft_align_size(size + ft_header_size(), getpagesize());
	block = ft_request_memory(last + ft_header_size(), pages);
	block->size = pages - ft_header_size();
	block->prev = last;
	block->next = NULL;
	return (block);
}

t_block			*ft_request_memory(void *last, size_t size)
{
	t_block *tmp;

	if ((tmp = mmap(last, size, PROT_READ | PROT_WRITE | PROT_EXEC,\
		MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
	{
		return (NULL);
	}
	return (tmp);
}

void			ft_move_block_to_use(int type, t_block *block)
{
	ft_delete_block(&g_heap[type].free, block);
	ft_insert_block_top(&g_heap[type].in_use, block);
}

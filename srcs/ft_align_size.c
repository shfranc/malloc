/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:35:11 by sfranc            #+#    #+#             */
/*   Updated: 2018/07/05 17:59:07 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		ft_header_size(void)
{
	return (ft_align_size(sizeof(t_block), 16));
}

size_t		ft_align_size(size_t size, size_t multiple)
{
	if (size == 0)
		return (multiple);
	return (((((size) - 1) / multiple) * multiple) + multiple);
}

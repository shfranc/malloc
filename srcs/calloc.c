/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:01:06 by sfranc            #+#    #+#             */
/*   Updated: 2018/07/05 18:11:52 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*ft_memset(void *b, int c, size_t len)
{
	char *temp;

	temp = (char*)b;
	while (len-- > 0)
	{
		*temp++ = (unsigned char)c;
	}
	return (b);
}

void			ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void			*calloc(size_t count, size_t size)
{
	void	*data;

	data = malloc(count * size);
	if (data)
		ft_bzero(data, count * size);
	ft_mode_log() ? ft_log(CALLOC, NULL) : 0;
	return (data);
}

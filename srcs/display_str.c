/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:35:11 by sfranc            #+#    #+#             */
/*   Updated: 2018/07/05 17:54:25 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static size_t	ft_strlen(const char *s)
{
	char const *temp;

	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void			ft_putstr(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

void			ft_putstr_fd(int fd, char const *str)
{
	if (str)
		write(fd, str, ft_strlen(str));
}

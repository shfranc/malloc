#include "malloc.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

static size_t	ft_strlen(const char *s)
{
	char const *temp;

	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

void			ft_putendl(char const *str)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
}

void			ft_putstr(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}

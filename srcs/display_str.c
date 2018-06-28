#include "malloc.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
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

void			ft_putendl_2(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		write(1, s1, ft_strlen(s1));
		write(1, s2, ft_strlen(s2));
		write(1, "\n", 1);
	}
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
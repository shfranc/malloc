#include "malloc.h"

void	ft_putnbr(int n)
{
	long int	nb;
	int			len;
	char		s[10];

	nb = (long int)n;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	len = 0;
	while (nb > 0)
	{
		s[len++] = nb % 10 + 48;
		nb = nb / 10;
	}
	while (len-- > 0)
		ft_putchar(s[len]);
}

void	ft_putnbr_fd(int fd, int n)
{
	long int	nb;
	int			len;
	char		s[10];

	nb = (long int)n;
	if (nb == 0)
		ft_putchar_fd(fd, '0');
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd(fd, '-');
	}
	len = 0;
	while (nb > 0)
	{
		s[len++] = nb % 10 + 48;
		nb = nb / 10;
	}
	while (len-- > 0)
		ft_putchar_fd(fd, s[len]);
}

void	ft_putnbr_endl(int n)
{
	long int	nb;
	int			len;
	char		s[10];

	nb = (long int)n;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	len = 0;
	while (nb > 0)
	{
		s[len++] = nb % 10 + 48;
		nb = nb / 10;
	}
	while (len-- > 0)
		ft_putchar(s[len]);
	ft_putchar('\n');
}

void	ft_putullnbr_endl(unsigned long long int n)
{
	int			len;
	char		s[16];

	if (n == 0)
		ft_putchar('0');
	len = 0;
	while (n > 0)
	{
		s[len++] = n % 10 + 48;
		n = n / 10;
	}
	while (len-- > 0)
		ft_putchar(s[len]);
	ft_putchar('\n');
}

void	ft_putnbr_str(char *str, int n)
{
	ft_putstr(str);
	ft_putchar(' ');
	ft_putnbr_endl(n);
}

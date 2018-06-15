#include "malloc.h"

void			ft_putaddr(unsigned long long ptr)
{	
	char	hex[16] = "0123456789abcdef";
	char	s[16];
	int		i;

	i = 0;
	if (ptr == 0)
		s[i++] = '0';
	while(ptr != 0)
	{
		s[i++] = hex[ptr % 16];	
		ptr /= 16;
	}
	write(1, "0x", 2);
	while (i--)
		ft_putchar(s[i]);
}

void			ft_putaddr_endl(unsigned long long ptr)
{	
	char	hex[16] = "0123456789abcdef";
	char	s[16];
	int		i;

	i = 0;
	if (ptr == 0)
		s[i++] = '0';
	while(ptr != 0)
	{
		s[i++] = hex[ptr % 16];	
		ptr /= 16;
	}
	write(1, "0x", 2);
	while (i--)
		ft_putchar(s[i]);
	write(1, "\n", 1);
}

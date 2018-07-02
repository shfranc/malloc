#include "malloc.h"

void	ft_print_memory(const void *addr, size_t size)
{
	char	hex[16] = "0123456789abcdef";
	char	s[16] = "0000000000000000";
	int		temp;
	size_t	i;
	size_t	a;

	i = 0;
	while (i < size)
	{
		temp = *(char*)addr >> 4 & 0x0F;
		write(1, &hex[temp], 1);
		temp = *(char*)addr & 0x0F;
		write(1, &hex[temp], 1);
		s[i % 16] = *(char*)addr;
		if (s[i % 16] < 32 || s[i % 16] > 126)
			s[i % 16] = '.';
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
		{
			write(1, s, 16);
			write(1, "\n", 1);
			a = 0;
			while (a < 16)
				s[a++] = 0;
		}
		addr++;
	}
	if (i % 16 != 0)
	{
		a = i;
		while (a % 16 != 0)
		{
			write(1, "  ", 2);
			if (a % 2 == 0)
				write(1, " ", 1);
			a++;
		}
		if (i % 2 == 1)
			write(1, " ", 1);
		write(1, s, i % 16);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

#include "malloc.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *temp;

	temp = (char*)b;
	while (len-- > 0)
	{
		*temp++ = (unsigned char)c;
	}
	return (b);
}

int		main(void)
{
	char *s1;
	char *s2;
	char *s3;

	if ((s1 = (char *)ft_malloc(5150)))
	{
		s1 = ft_memset(s1, '1', 11);
		ft_putstr(GREEN);
		ft_putstr("--> s1: ");
		ft_putaddr_endl((unsigned long long)(s1));
		ft_putendl(s1);		
		ft_putstr(RESET);
	}
	else
		ft_putendl("Unable to malloc");

	if ((s2 = (char *)ft_malloc(5170)))
	{
		s2 = ft_memset(s2, '2', 11);
		ft_putstr(GREEN);
		ft_putstr("--> s2: ");
		ft_putaddr_endl((unsigned long long)(s2));
		ft_putendl(s2);		
		ft_putstr(RESET);
	}
	else
		ft_putendl("Unable to malloc");

	if ((s3 = (char *)ft_malloc(5190)))
	{
		s3 = ft_memset(s3, '3', 11);
		ft_putstr(GREEN);
		ft_putstr("--> s3: ");
		ft_putaddr_endl((unsigned long long)(s3));
		ft_putendl(s3);
		ft_putstr(RESET);
	}
	else
		ft_putendl("Unable to malloc");

	show_alloc_mem();

	return (0);
}

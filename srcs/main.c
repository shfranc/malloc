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
	char 	*s1;
	char 	*s2;
	char 	*s3;
	int		i;

	// s1 = (char *)malloc(17);
	// ft_memset(s1, '1', 17);

	// s2 = (char *)malloc(17);
	// ft_memset(s2, '2', 17);
	
	// s3 = (char *)malloc(17);
	// ft_memset(s3, '3', 17);

	// show_alloc_mem();

	// free(s2);
	// free(s1);
	// free(s3);

	// show_alloc_mem();

	// s3 = (char *)malloc(17);
	// ft_memset(s3, '3', 17);
	// show_alloc_mem();
	
	// free(s3);
	
	// show_alloc_mem();

	s3 = (char *)malloc(17);
	ft_putaddr_endl((unsigned long long)s3);

	ft_memset(s3, '3', 17);	
	show_alloc_mem();

	s3 = (char *)realloc(s3, 180);
	ft_putaddr_endl((unsigned long long)s3);
	show_alloc_mem();
	ft_memset(s3, '3', 180);

	free(s3);
	show_alloc_mem();

	// s1 = (char *)malloc(600);
	// ft_memset(s1, '1', 600);

	// s2 = (char *)malloc(600);
	// ft_memset(s2, '2', 600);
	
	// s3 = (char *)malloc(600);
	// ft_memset(s3, '3', 600);

	// show_alloc_mem();

	// free(s1);
	// free(s2);
	// free(s3);
	
	// show_alloc_mem();

	// s1 = (char *)malloc(10000);
	// ft_memset(s1, '1', 10000);

	// s2 = (char *)malloc(10000);
	// ft_memset(s2, '2', 10000);
	
	// s3 = (char *)malloc(10000);
	// ft_memset(s3, '3', 10000);
	
	// show_alloc_mem();


	// free(s3);
	// free(s1);
	// free(s2);	
	
	// show_alloc_mem();


	// s1 = (char *)ft_malloc(1000);
	// i = 1000;
	// while (i--)
	// {
	// 	s1 = (char *)ft_malloc(1024);
	// 	ft_memset(s1, '*', 1024);
	// }

	// i = 100;
	// while (i--)
	// {
	// 	s1 = (char *)ft_malloc(TINY_BLOCK);
	// 	ft_memset(s1, '*', TINY_BLOCK);
	// }

	// i = 100;
	// while (i--)
	// {
	// 	s2 = (char *)ft_malloc(SMALL_BLOCK);
	// 	ft_memset(s2, '*', SMALL_BLOCK);
	// }

	// i = 100;
	// while (i--)
	// {
	// 	s3 = (char *)ft_malloc(SMALL_BLOCK * 2 - 100);
	// 	ft_memset(s3, '*', SMALL_BLOCK * 2 - 100);
	// }

	// if ((s1 = (char *)ft_malloc(3515)))
	// {
	// 	s1 = ft_memset(s1, '1', 11);
	// 	ft_putstr(GREEN);
	// 	ft_putstr("--> s1: ");
	// 	ft_putaddr_endl((unsigned long long)(s1));
	// 	ft_putendl(s1);		
	// 	ft_putstr(RESET);
	// }
	// else
	// 	ft_putendl("Unable to malloc");

	// if ((s2 = (char *)ft_malloc(3517)))
	// {
	// 	s2 = ft_memset(s2, '2', 11);
	// 	ft_putstr(GREEN);
	// 	ft_putstr("--> s2: ");
	// 	ft_putaddr_endl((unsigned long long)(s2));
	// 	ft_putendl(s2);		
	// 	ft_putstr(RESET);
	// }
	// else
	// 	ft_putendl("Unable to malloc");

	// if ((s3 = (char *)ft_malloc(519)))
	// {
	// 	s3 = ft_memset(s3, '3', 11);
	// 	ft_putstr(GREEN);
	// 	ft_putstr("--> s3: ");
	// 	ft_putaddr_endl((unsigned long long)(s3));
	// 	ft_putendl(s3);
	// 	ft_putstr(RESET);
	// }
	// else
	// 	ft_putendl("Unable to malloc");


	return (0);
}

#include "malloc.h"

static void	*ft_memset(void *b, int c, size_t len)
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
	show_alloc_mem();
	return (0);
}

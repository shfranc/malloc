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

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*calloc(size_t count, size_t size)
{
	void	*data;

	data = malloc(count * size);
	if (data)
	{
		ft_bzero(data, count * size);
	}
	// ft_print_debug(4, data - ft_header_size());
	return (data);
}
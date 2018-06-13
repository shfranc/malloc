#include "malloc.h"

int		main(void)
{
	char *str;
	unsigned long long	 a = 1;

	ft_putnbr_str("sizeof ull: ", sizeof(a));

	str = (char *)ft_malloc(12);
	str = (char *)ft_malloc(12);

	return (0);
}

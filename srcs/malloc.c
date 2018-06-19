#include "malloc.h"
#include <stdio.h>

static void		ft_check_limit(void)
{
	struct rlimit	rlp;

	if (getrlimit(RLIMIT_DATA, &rlp) == 0)
	{
		// ft_putullnbr_endl(rlp.rlim_cur);
		// ft_putullnbr_endl(rlp.rlim_max);
		printf("%llu\n", rlp.rlim_cur);
		printf("%llu\n", rlp.rlim_max);
	}

}

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}

void	*malloc(size_t size)
{

	size = ft_align_size(size, 16);
	ft_putnbr_str("size:", size);


	return (NULL);
}

#include "malloc.h"

size_t 		ft_align_size(size_t size, size_t multiple)
{
	if (size == 0)
		return (multiple);
	return (((((size) - 1) / multiple) * multiple) + multiple);
}
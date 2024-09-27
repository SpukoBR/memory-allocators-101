#include "memalloc.h"

void	*ft_calloc(size_t num, size_t nsize)
{
	size_t	size;
	void	*block;

	if (!num || !nsize)
		return (NULL);
	size = num * nsize;
	if (nsize != size / num)
		return (NULL);
	block = ft_malloc(size);
	if (!block)
		return (NULL);
	memset(block, 0, size);
	return (block);
}

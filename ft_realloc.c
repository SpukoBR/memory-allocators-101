#include "memalloc.h"

void	*ft_realloc(void *block, size_t size)
{
	t_header	*header;
	void		*ret;

	if (!block || !size)
		return (ft_malloc(size));
	header = (t_header *)block - 1;
	if (header->s.s_size >= size)
		return (block);
	ret = ft_malloc(size);
	if (ret)
	{
		memcpy(ret, block, header->s.s_size);
		ft_free(block);
	}
	return (ret);
}

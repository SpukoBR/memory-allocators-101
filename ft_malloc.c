#include "memalloc.h"

t_header		*g_head = NULL;
t_header		*g_tail = NULL;
pthread_mutex_t	g_malloc_lock = PTHREAD_MUTEX_INITIALIZER;

void	*ft_malloc(size_t size)
{
	size_t		total_size;
	void		*block;
	t_header	*header;

	if (!size)
		return (NULL);
	pthread_mutex_lock(&g_malloc_lock);
	header = get_free_block(size);
	if (header)
	{
		header->s.s_is_free = 0;
		pthread_mutex_unlock(&g_malloc_lock);
		return ((void *)(header + 1));
	}
	total_size = sizeof(t_header) + size;
	block = sbrk(total_size);
	if (block == (void *)-1)
	{
		pthread_mutex_unlock(&g_malloc_lock);
		return (NULL);
	}
	header = block;
	header->s.s_size = size;
	header->s.s_is_free = 0;
	header->s.s_next = NULL;
	if (!g_head)
		g_head = header;
	if (g_tail)
		g_tail->s.s_next = header;
	g_tail = header;
	pthread_mutex_unlock(&g_malloc_lock);
	return ((void *)(header + 1));
}

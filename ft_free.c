#include "memalloc.h"

void	ft_free(void *block)
{
	t_header	*header;
	t_header	*tmp;

	void *programbreak ;
	if (!block)
		return ;
	pthread_mutex_lock(&g_malloc_lock);
	header = (t_header *)block - 1;
	programbreak = sbrk(0);
	if ((char *)block + header->s.s_size == programbreak)
	{
		if (g_head == g_tail)
		{
			g_head = g_tail = NULL;
		}
		else
		{
			tmp = g_head;
			while (tmp)
			{
				if (tmp->s.s_next == g_tail)
				{
					tmp->s.s_next = NULL;
					g_tail = tmp;
				}
				tmp = tmp->s.s_next;
			}
		}
		sbrk(0 - sizeof(t_header) - header->s.s_size);
		pthread_mutex_unlock(&g_malloc_lock);
		return ;
	}
	header->s.s_is_free = 1;
	pthread_mutex_unlock(&g_malloc_lock);
}

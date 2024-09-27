#ifndef MEMALLOC_H
# define MEMALLOC_H

# include <pthread.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>

# define ALIGN_SIZE 16

typedef char			t_align[ALIGN_SIZE];

typedef union u_header
{
	struct
	{
		size_t			s_size;
		unsigned		s_is_free;
		struct u_header	*s_next;
	} s;
	t_align				s_stub;
}						t_header;

extern t_header			*g_head;
extern t_header			*g_tail;
extern pthread_mutex_t	g_malloc_lock;

void					*ft_malloc(size_t size);
void					ft_free(void *block);
void					*ft_calloc(size_t num, size_t nsize);
void					*ft_realloc(void *block, size_t size);

static t_header			*get_free_block(size_t size);

#endif

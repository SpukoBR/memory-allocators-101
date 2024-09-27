NAME = memalloc.so
SRCS = ft_malloc.c ft_free.c ft_calloc.c ft_realloc.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -fPIC
LDFLAGS = -shared

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

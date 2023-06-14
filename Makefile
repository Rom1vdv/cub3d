NAME = cub3d

FILES = main raycasting raycasting2

UTILS_FILES = \

SRCS = $(addprefix utils/, $(addsuffix .c, $(UTILS_FILES))) \
	$(addprefix sources/, $(addsuffix .c, $(FILES)))

OBJS = ${SRCS:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./includes


$(NAME): $(OBJS)
		$(CC) $(SANITIZE) $(CFLAGS) -o $@ $(OBJS)

all:    $(NAME)

clean:
		$(RM) $(OBJS)

fclean:         clean
		$(RM) $(NAME) $(MLX)
		
re: fclean all

.PHONY: all clean fclean re
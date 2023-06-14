NAME = cub3d

FILES = main mlx mlx_utils raycasting raycasting2

UTILS_FILES = \

SRCS = $(addprefix utils/, $(addsuffix .c, $(UTILS_FILES))) \
	$(addprefix sources/, $(addsuffix .c, $(FILES)))

OBJS = ${SRCS:.c=.o}

RM = rm -f

CC = gcc

MLX = libmlx.dylib

CFLAGS = -Wall -Wextra -Werror -I ./includes -I ./mlx -fsanitize=address -g

LIBS =  -lmlx -Lmlx -framework OpenGL -framework Appkit

$(NAME): $(MLX) $(OBJS)
		$(CC) $(SANITIZE) $(CFLAGS) $(LIBS) -o $@ $(MLX) $(OBJS) 

$(MLX) :
		make -C mlx
		mv ./mlx/$(MLX) .

all:    $(NAME)

clean:
		$(RM) $(OBJS)

fclean:         clean
		$(RM) $(NAME) $(MLX)
		make clean -C mlx
re: fclean all

.PHONY: all clean fclean re
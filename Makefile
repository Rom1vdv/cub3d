NAME = cub3d

FILES = main init_mlx/mlx init_mlx/mlx_utils raycasting/raycasting raycasting/raycasting2 \
		parsing/check_map parsing/check parsing/get_map

UTILS_FILES = ft_split utils utils2

SRCS = $(addprefix utils/, $(addsuffix .c, $(UTILS_FILES))) \
	$(addprefix sources/, $(addsuffix .c, $(FILES))) \

OBJS_DIR = objs

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

RM = rm -f

CC = gcc

MLX = libmlx.dylib

CFLAGS = -Wall -Wextra -Werror -I ./includes -I ./mlx -I ./sources/gnl -fsanitize=address -g

LIBS =  -lmlx -Lmlx -framework OpenGL -framework Appkit

# Colors #
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
GREEN = \033[32m
YELLOW = \033[33m
CYAN = \033[36m

# Rules #


$(NAME): $(MLX) $(OBJS)
		@echo "$(BOLD)Linking $(CYAN)$@$(RESET)"
		$(CC) $(SANITIZE) $(CFLAGS) $(LIBS) -o $@ $(MLX) $(OBJS) 

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BOLD)Compiling $(YELLOW)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX) :
		make -C mlx
		mv ./mlx/$(MLX) .

all:    $(NAME)

clean:
		@echo "$(BOLD)Cleaning objects$(RESET)"
		$(RM) $(OBJS)

fclean:         clean
		@echo "$(BOLD)Cleaning $(YELLOW)$(NAME)$(RESET)"
		$(RM) $(NAME) $(MLX)
		make clean -C mlx
re: fclean all

.PHONY: all clean fclean re
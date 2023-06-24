NAME = cub3D

SRCS_DIR = sources

SRCS = main.c \
		error/error_handler.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		parsing/check_map.c \
		parsing/get_map.c \
		parsing/parsing.c \
		parsing/check.c \
		utils/utils.c \
		utils/utils2.c \
		utils/ft_split.c \
		rendering/mlx_utils.c \
		rendering/mlx.c\
		rendering/cube_loop.c\
		rendering/render.c\
		raycasting/raycasting.c\
		raycasting/raycasting2.c\
		raycasting/controls.c

OBJS_DIR = objs

MLX = libmlx_Linux.a
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes -I ./mlx -g
SFLAGS = -fsanitize=address -g
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
RM = rm -f

# Special condition to compile mlx on Linux DO NOT FORGET TO REMOVE BEFOR FINAL PUSH
ifeq ($(shell uname), Linux)
	MLXFLAGS = -Lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	CFLAGS = -Wall -Wextra -Werror -I ./includes -g
endif

# Colors
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
GREEN = \033[32m
YELLOW = \033[33m
CYAN = \033[36m

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
	@echo "$(BOLD)Linking $(CYAN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(SFLAGS) $(OBJS) $(MLXFLAGS) libmlx_Linux.a -o $(NAME)

$(MLX) : 
		@echo "Created MLX"
		make -C mlx_linux
		mv ./mlx_linux/$(MLX) .

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BOLD)Compiling $(YELLOW)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BOLD)Cleaning objects$(RESET)"
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@echo "$(BOLD)Cleaning $(YELLOW)$(NAME)$(RESET)"
	@$(RM) $(NAME) $(MLX)
	make clean -C mlx_linux

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 20:07:41 by aburnott          #+#    #+#              #
#    Updated: 2023/06/05 14:52:33 by aburnott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		init_mlx/init_mlx.c \
		init_mlx/mlx_utils.c
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SFLAGS = -g3 -fsanitize=address
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
RM = rm -f

# Special condition to compile mlx on Linux DO NOT FORGET TO REMOVE BEFOR FINAL PUSH
ifeq ($(shell uname), Linux)
	MLXFLAGS = -Lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
endif

# Colors
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
GREEN = \033[32m
YELLOW = \033[33m
CYAN = \033[36m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BOLD)Linking $(CYAN)$@$(RESET)"
	@$(CC) $(CFLAGS) $(SFLAGS) -g $(MLXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BOLD)Compiling $(YELLOW)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BOLD)Cleaning objects$(RESET)"
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@echo "$(BOLD)Cleaning $(YELLOW)$(NAME)$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
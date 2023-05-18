# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 20:07:41 by aburnott          #+#    #+#              #
#    Updated: 2023/05/18 21:24:44 by aburnott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS = sources/main.c \
		sources/gnl/get_next_line.c \
		sources/gnl/get_next_line_utils.c \
		sources/parsing/check_map.c \
		sources/parsing/parsing.c
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(notdir $(SRCS:.c=.o)))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
RM = rm -f

# Special condition to compile mlx on Linux
ifeq ($(shell uname), Linux)
	MLXFLAGS = -Lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
endif

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $@"
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects"
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@echo "Cleaning $(NAME)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
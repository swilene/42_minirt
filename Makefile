# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saguesse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 14:54:21 by saguesse          #+#    #+#              #
#    Updated: 2023/03/03 17:39:50 by saguesse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

INC = -I include
HEADER = include/miniRT.h

MLX_PATH = ./mlx_linux
MLX = $(MLX_PATH)/libmlx.a
HEADER_MLX = $(MLX_PATH)/mlx.h

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
HEADER_LIBFT = $(LIBFT_PATH)/libft.h

SRC_DIR = srcs
SRC_FILES = main.c \
			check_file.c \
			check_inputs.c \
			check_numbers.c \
			init_structures.c \
			init_lists.c \
			window.c \
			render.c \
			recalculate.c \
			clear.c
SRC = $(SRC_FILES:%=$(SRC_DIR)/%)

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(HEADER) $(HEADER_MLX) $(HEADER_LIBFT)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(HEADER) $(INC) $(LIBFT) $(MLX) -L/usr/lib -lXext -lX11 -lm

$(MLX):
	make -C $(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC) -I . -I libft -I libft/ft_printf -I mlx_linux -I/usr/include

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean
	make all

.PHONY: all clean fclean re

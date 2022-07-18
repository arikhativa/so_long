# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/07/18 11:40:24 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# lib42
LIB_NAME = lib42.a
LIB_PATH = lib42
LIB  = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

# mlx
# LIBMLX_NAME = libmlx.a
# LIBMLX_PATH = libmlx
# LIBMLX = $(addprefix $(LIBMLX_PATH)/, $(LIBMLX_NAME))
# LIBMLX_HED_DIR = $(LIBMLX_PATH)
# MLX_CFLAGS = "-O2 -Wno-deprecated-declarations"

# mlx - linux
LIBMLX_NAME = libmlx_Linux.a
LIBMLX_PATH = minilibx-linux
LIBMLX = $(addprefix $(LIBMLX_PATH)/, $(LIBMLX_NAME))
LIBMLX_HED_DIR = $(LIBMLX_PATH)

# gnl
GNL_DIR = $(LIB_PATH)/get_next_line
GNL_HED_DIR = $(GNL_DIR)

# ft_printf
FT_PRINTF_DIR = $(LIB_PATH)/ft_printf
FT_PRINTF_HED_DIR = $(FT_PRINTF_DIR)

# libft
LIBFT_DIR = $(FT_PRINTF_DIR)/libft
LIBFT_HED_DIR = $(LIBFT_DIR)

# so_long
SO_LONG_HED_DIR = include
SO_LONG_HED = $(addprefix $(SO_LONG_HED_DIR)/, $(wildcard *.h))
SRC = $(wildcard src/**/*.c) $(SRC_GNL)
OBJ = $(SRC:.c=.o)

# header

CC = gcc
#  TODO
# CFLAGS = -Wall -Werror -Wextra
HED_INCLUD = -I$(LIBFT_HED_DIR) -I$(FT_PRINTF_HED_DIR) -I$(GNL_HED_DIR) -I$(SO_LONG_HED_DIR) -I$(LIBMLX_HED_DIR)
CFLAGS = -c
LDFLAGS = -L$(LIB_PATH) -L$(LIBMLX_PATH) -L/usr/lib
LDLIBS = -l42 -lmlx -lmlx_Linux -lm -lz -lXext -lX11
# LDFLAGS = -L $(LIB_PATH) -L $(LIBMLX_PATH)
# LDLIBS = -l -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean re all

%.o: %.c $(SO_LONG_HED)
	$(CC) $(CFLAGS) $< $(HED_INCLUD) -o $@ 

all: $(NAME)

$(LIBMLX):
	$(MAKE) -sC ./$(LIBMLX_PATH)
# $(MAKE) -sC ./$(LIBMLX_PATH) CFLAGS=$(MLX_CFLAGS)

$(LIB):
	$(MAKE) all -sC ./$(LIB_PATH)

$(NAME): $(OBJ) $(LIB) $(LIBMLX)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) clean -sC ./$(LIBMLX_PATH)
	$(MAKE) fclean -sC ./$(LIB_PATH)
	$(RM) $(NAME)

re: fclean all

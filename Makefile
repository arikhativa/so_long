# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/07/18 13:36:02 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

ifeq ($(OS),linux)
LIBMLX_NAME = libmlx_Linux.a
LIBMLX_PATH = minilibx-linux
LDFLAGS = -L$(LIB_PATH) -L$(LIBMLX_PATH) -L/usr/lib
LDLIBS = -l42 -lmlx -lmlx_Linux -lm -lz -lXext -lX11
endif

ifndef ($(OS))
LIBMLX_NAME = libmlx.a
LIBMLX_PATH = libmlx
MLX_CFLAGS = " -Wno-deprecated-declarations"
LDFLAGS = -L$(LIB_PATH) -L$(LIBMLX_PATH)
LDLIBS = -l42 -lmlx -framework OpenGL -framework AppKit
endif

# lib42
LIB_NAME = lib42.a
LIB_PATH = lib42
LIB  = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

# mlx
LIBMLX = $(addprefix $(LIBMLX_PATH)/, $(LIBMLX_NAME))
LIBMLX_HED_DIR = $(LIBMLX_PATH)

# mlx
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
CFLAGS = -c
HED_INCLUD = -I$(LIBFT_HED_DIR) -I$(FT_PRINTF_HED_DIR) -I$(GNL_HED_DIR) -I$(SO_LONG_HED_DIR) -I$(LIBMLX_HED_DIR)

.PHONY: clean fclean re all

%.o: %.c $(SO_LONG_HED)
	$(CC) $(CFLAGS) $< $(HED_INCLUD) -o $@ 

all: $(NAME)

$(LIBMLX):
	$(MAKE) -sC ./$(LIBMLX_PATH) CFLAGS+=$(MLX_CFLAGS)

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/07/23 14:29:50 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# lib42
LIB_NAME = lib42.a
LIB_PATH = lib42
LIB  = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

# mlx
LIBMLX_NAME = libmlx.a
LIBMLX_PATH = libmlx
MLX_CFLAGS = " -Wno-deprecated-declarations"
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
SO_LONG_HED = $(wildcard $(SO_LONG_HED_DIR)/*.h)
SRC = $(wildcard src/**/*.c) $(SRC_GNL)
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -c
# CFLAGS = -Wall -Werror -Wextra -c
LDFLAGS = -L$(LIB_PATH) -L$(LIBMLX_PATH)
LDLIBS = -l42 -lmlx -framework OpenGL -framework AppKit -lm -lz
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
	$(MAKE) clean -sC ./$(LIB_PATH)
	$(MAKE) clean -sC ./$(LIBMLX_PATH)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) clean -sC ./$(LIBMLX_PATH)
	$(MAKE) fclean -sC ./$(LIB_PATH)
	$(RM) $(NAME)

re: fclean all

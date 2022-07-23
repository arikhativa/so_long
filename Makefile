# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/07/23 16:30:27 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# lib42
LIB42_NAME = lib42.a
LIB42_PATH = lib42
LIB42  = $(addprefix $(LIB42_PATH)/, $(LIB42_NAME))

# mlx
LIBMLX_NAME = libmlx.a
LIBMLX_PATH = libmlx
LIBMLX = $(addprefix $(LIBMLX_PATH)/, $(LIBMLX_NAME))
LIBMLX_HEAD_DIR = $(LIBMLX_PATH)
MLX_CFLAGS = " -Wno-deprecated-declarations"

# gnl
GNL_DIR = $(LIB42_PATH)/get_next_line
GNL_HEAD_DIR = $(GNL_DIR)

# ft_printf
FT_PRINTF_DIR = $(LIB42_PATH)/ft_printf
FT_PRINTF_HEAD_DIR = $(FT_PRINTF_DIR)

# libft
LIBFT_DIR = $(FT_PRINTF_DIR)/libft
LIBFT_HEAD_DIR = $(LIBFT_DIR)

# so_long
SO_LONG_HEAD_DIR = include
SO_LONG_HEAD_NAME = \
	collect.h \
	define.h \
	draw.h \
	error.h \
	handler.h \
	hook.h \
	image.h \
	input.h \
	map.h \
	meta.h \
	object.h \
	player.h \
	point.h \
	print.h \
	sprite.h \
	tab.h

SO_LONG_HEAD = $(addprefix $(SO_LONG_HEAD_DIR)/, $(SO_LONG_HEAD_NAME))

SRC = \
	src/collect/collect.c \
	src/collect/collect_get.c \
	src/collect/collect_set.c \
	src/draw/draw.c \
	src/draw/draw_finish_game.c \
	src/draw/draw_map.c \
	src/draw/draw_move_counter.c \
	src/error/error.c \
	src/handler/handler.c \
	src/hook/hook.c \
	src/image/image.c \
	src/image/image_get.c \
	src/input/input.c \
	src/main/main.c \
	src/map/char_validate.c \
	src/map/line_validate.c \
	src/map/map.c \
	src/map/map_clean.c \
	src/map/map_get.c \
	src/map/map_is.c \
	src/map/map_set.c \
	src/map/map_validate.c \
	src/meta/meta.c \
	src/meta/meta_get.c \
	src/player/player.c \
	src/player/player_get.c \
	src/player/player_move.c \
	src/player/player_move_counter.c \
	src/player/player_set.c \
	src/point/point.c \
	src/point/point_move.c \
	src/print/print.c \
	src/sprite/sprite.c \
	src/tab/tab.c \
	src/tab/tab_get_char.c \
	src/tab/tab_set.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
LDFLAGS = -L$(LIB42_PATH) -L$(LIBMLX_PATH)
LDLIBS = -l42 -lmlx -framework OpenGL -framework AppKit -lm -lz
HEAD_INCLUD = -I$(LIBFT_HEAD_DIR) -I$(FT_PRINTF_HEAD_DIR) -I$(GNL_HEAD_DIR) -I$(SO_LONG_HEAD_DIR) -I$(LIBMLX_HEAD_DIR)

.PHONY: clean fclean re all

%.o: %.c $(SO_LONG_HEAD)
	$(CC) $(CFLAGS) $< $(HEAD_INCLUD) -o $@ 

all: $(NAME)

$(LIBMLX):
	$(MAKE) -sC ./$(LIBMLX_PATH) CFLAGS+=$(MLX_CFLAGS)

$(LIB42):
	$(MAKE) all -sC ./$(LIB42_PATH)

$(NAME): $(OBJ) $(LIB42) $(LIBMLX) $(SO_LONG_HEAD)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

clean:
	$(MAKE) clean -sC ./$(LIB42_PATH)
	$(MAKE) clean -sC ./$(LIBMLX_PATH)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) clean -sC ./$(LIBMLX_PATH)
	$(MAKE) fclean -sC ./$(LIB42_PATH)
	$(RM) $(NAME)

re: fclean all

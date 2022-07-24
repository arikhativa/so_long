# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/07/24 12:40:23 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft
LIBFT  = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

# mlx
LIBMLX_NAME = libmlx.a
LIBMLX_PATH = libmlx
LIBMLX = $(addprefix $(LIBMLX_PATH)/, $(LIBMLX_NAME))
LIBMLX_HEAD_DIR = $(LIBMLX_PATH)
MLX_CFLAGS = " -Wno-deprecated-declarations"

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

CC = cc
CFLAGS = -Wall -Werror -Wextra -c
LDFLAGS = -L$(LIBFT_DIR) -L$(LIBMLX_PATH)
LDLIBS = -lft -lmlx -framework OpenGL -framework AppKit
HEAD_INCLUD = -I$(LIBFT_DIR) -I$(SO_LONG_HEAD_DIR) -I$(LIBMLX_HEAD_DIR)

.PHONY: clean fclean re all

%.o: %.c $(SO_LONG_HEAD)
	$(CC) $(CFLAGS) $< $(HEAD_INCLUD) -o $@ 

all: $(NAME)

$(LIBMLX):
	$(MAKE) -sC ./$(LIBMLX_PATH) CFLAGS+=$(MLX_CFLAGS)

$(LIBFT):
	$(MAKE) all -sC ./$(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX) $(SO_LONG_HEAD)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

clean:
	$(MAKE) clean -sC ./$(LIBFT_DIR)
	$(MAKE) clean -sC ./$(LIBMLX_PATH)
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) clean -sC ./$(LIBMLX_PATH)
	$(MAKE) fclean -sC ./$(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

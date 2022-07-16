# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/07/16 09:58:33 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HED_PATH = include

LIBFT_NAME = libft.a
LIBFT_PATH = libft/
LIBFT  = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))
# LIBMLX_PATH = libmlx-linux/
# LIBMLX_NAME = libmlx_Linux.a
# LIBMLX  = $(addprefix $(LIBMLX_PATH), $(LIBMLX_NAME))
LIBMLX_PATH = libmlx/
LIBMLX_NAME = libmlx.a
LIBMLX  = $(addprefix $(LIBMLX_PATH), $(LIBMLX_NAME))

GNL = get_next_line.c get_next_line_utils.c
GNL_PATH = get_next_line/
SRC_GNL = $(addprefix $(GNL_PATH), $(GNL))

MLX_CFLAGS = "-O2 -Wno-deprecated-declarations"

CC = gcc
#  TODO
CFLAGS = -c -I$(HED_PATH) -I$(LIBFT_PATH) -I$(LIBMLX_PATH) -I$(GNL_PATH)
# CFLAGS = -Wall -Werror -Wextra -c -I$(HED_PATH) -I$(LIBFT_PATH) -I$(LIBMLX_PATH)
LDFLAGS = -L $(LIBFT_PATH) -L $(LIBMLX_PATH)
# LDLIBS = -lft -lmlx -lXext -lX11 -lbsd
LDLIBS = -lft -lmlx -framework OpenGL -framework AppKit
RM = rm -f

SRC = $(wildcard src/**/*.c) $(SRC_GNL)
OBJ = $(SRC:.c=.o)
HED = $(wildcard $(HED_PATH)/**/*.h)

.PHONY: clean fclean re all bonus
.PRECIOUS: $(SRC) $(HED) $(LIBFT) $(LIBMLX) $(SRC_GNL)

all: $(NAME)

$(LIBMLX):
	$(MAKE) -sC ./$(LIBMLX_PATH) CFLAGS=$(MLX_CFLAGS)

$(LIBFT):
	$(MAKE) bonus -sC ./$(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX) $(HED) Makefile
	echo $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@

bonus: $(NAME) 

clean:
# $(MAKE) clean -C ./$(LIBMLX_PATH)
# $(MAKE) clean -C ./$(LIBFT_PATH)
	$(RM) $(OBJ)

fclean: clean
# $(MAKE) clean -C ./$(LIBMLX_PATH)
# $(MAKE) fclean -C ./$(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all


# Docker TODO
IMG=arikhatica/minilibx:ubuntu
NAME=minilibx
WORKDIR=/home

build:
	docker build -t $(IMG) .

run:
	docker run -d -it -v ~:$(WORKDIR)/ --name $(NAME) $(IMG) -p 555:555

stop:
	docker rm -f $(NAME)

enter:
	docker exec -it $(NAME) bash


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 11:26:43 by yoav              #+#    #+#              #
#    Updated: 2022/07/23 18:02:32 by yrabby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib42.a

FT_PRINTF_NAME = libftprintf.a
FT_PRINTF_PATH = ft_printf
LIB_FT_PRINTF = $(addprefix $(FT_PRINTF_PATH)/, $(FT_PRINTF_NAME))

GNL_SRC = get_next_line_utils.c get_next_line.c
GNL_PATH = get_next_line
GNL_OBJ = $(addprefix $(GNL_PATH)/, $(GNL_SRC:.c=.o))
GNL_HEAD_DIR = $(GNL_PATH)
GNL_HEAD = $(addprefix $(GNL_PATH)/, get_next_line.h)

HEAD = $(GNL_HEAD)

CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -I$(HEAD)
ARFLAGS = rs

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) $< -o $@

all: $(NAME)

$(LIB_FT_PRINTF):
	$(MAKE) -sC $(FT_PRINTF_PATH)

$(NAME): $(GNL_OBJ) $(LIB_FT_PRINTF)
	cp $(LIB_FT_PRINTF) $@
	$(AR) $(ARFLAGS) $@ $(GNL_OBJ)

clean:
	$(MAKE) clean -sC $(FT_PRINTF_PATH)
	$(RM) $(GNL_OBJ)

fclean: clean
	$(MAKE) fclean -sC $(FT_PRINTF_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

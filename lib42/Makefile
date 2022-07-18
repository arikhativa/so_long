# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 11:26:43 by yoav              #+#    #+#              #
#    Updated: 2022/07/18 09:35:22 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib42.a

FT_PRINTF_NAME = libftprintf.a
FT_PRINTF_PATH = ft_printf
LIB_FT_PRINTF = $(addprefix $(FT_PRINTF_PATH)/, $(FT_PRINTF_NAME))

GNL_SRC = get_next_line_utils.c get_next_line.c
GNL_PATH = get_next_line
GNL_OBJ = $(addprefix $(GNL_PATH)/, $(GNL_SRC:.c=.o))
GNL_HED_DIR = $(GNL_PATH)
GNL_HED = $(addprefix $(GNL_PATH)/, get_next_line.h)

HED = $(GNL_HED)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(GNL_HED_DIR)
ARFLAGS = rcs

%.o: %.c $(HED)
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(LIB_FT_PRINTF):
	$(MAKE) -sC $(FT_PRINTF_PATH)

$(NAME): $(GNL_OBJ) $(LIB_FT_PRINTF)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(MAKE) clean -sC $(FT_PRINTF_PATH)
	$(RM) $(GNL_OBJ)

fclean: clean
	$(MAKE) fclean -sC $(FT_PRINTF_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/06/28 15:30:49 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
	input/percent_sign.c \
	input/parse_input.c \
	convert/itoa_base.c \
	convert/stoa_base.c \
	printable_mem/printable_mem.c \
	flag/flag.c \
	flag/parse_flag.c \
	flag/validate_flag.c \
	count/count_digit.c \
	generic/generic_unsigned_number.c \
	generic/generic.c \
	generic/generic_number.c \
	generic/zero_and_precision.c \
	ft_printf.c \
	print/print.c \
	handler/char.c \
	handler/hax_uppwer.c \
	handler/ptr.c \
	handler/str.c \
	handler/dec.c \
	handler/unsigned_dec.c \
	handler/hax_lower.c \
	list/list.c

BONUS_SRC = no.c

OBJ = $(SRC:.c=.o)
HED = include
BONUS_OBJ = $(BONUS_SRC:.c=.o)
LIBFT = libft

CC = gcc
#  TODO
# CFLAGS =  -c -I$(HED) -Ilibft
CFLAGS = -Wall -Werror -Wextra -c -I$(HED) -Ilibft
RM = rm -f
AR = ar -rcs

.PHONY: clean fclean re all bonus
.PRECIOUS: $(SRC) $(HED) $(LIBFT)

all: $(NAME)

t: all #TODO
	gcc -Iinclude test.c $(NAME)

$(NAME): $(OBJ) $(HED) Makefile
	$(MAKE) bonus -C ./$(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

bonus: $(NAME) 

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

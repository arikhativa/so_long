/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:01:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 14:51:34 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_H
# define GENERIC_H

# include <stdarg.h>
# include <stddef.h>

# include "flag.h"
# include "printable_mem.h"

size_t			get_smaller(size_t a, size_t b);
size_t			get_bigger(size_t a, size_t b);
size_t			generic_get_start(t_flag *f, size_t mem_size, \
									size_t digit, size_t pad);
t_printable_mem	*convert_generic_number(long nbr, t_flag *f, char *base);
t_printable_mem	*convert_generic_unsigned_number(size_t nbr, t_flag *f, \
					char *base);
size_t			get_size_for_number(t_flag *f, size_t digit, size_t pad);
size_t			add_precision_pad(char *ret, size_t pos, t_flag *f, \
									size_t nbr_len);
t_printable_mem	*create_empty_str(t_flag *f);
int				should_print_zero(int is_zero, t_flag *f);

#endif

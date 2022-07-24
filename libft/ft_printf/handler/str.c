/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:39:34 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 14:49:45 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "flag.h"
#include "libft.h"
#include "generic.h"
#include "printable_mem.h"
#include "handler.h"
#include "define.h"

static size_t	get_size_for_str(t_flag *f, size_t len)
{
	return (get_bigger(f->width, len));
}

static size_t	get_start_for_str(t_flag *f, size_t mem_size, size_t len)
{
	if (f->left_adjusted)
		return (0);
	return (mem_size - len);
}

t_printable_mem	*create_str_to_print(char *s, t_flag *f, size_t len)
{
	t_printable_mem	*m;
	size_t			start;
	size_t			size;

	if (f->is_precision)
		len = get_smaller(len, f->precision_value);
	size = get_size_for_str(f, len);
	m = create_printable_mem(f, size);
	if (m)
	{
		start = get_start_for_str(f, size, len);
		ft_memcpy((m->mem + start), s, len);
	}
	return (m);
}

t_printable_mem	*handle_str(va_list l, t_flag *f)
{
	char	*s;

	s = va_arg(l, char *);
	if (!s)
	{
		s = NULL_STR;
		if (f->is_precision && f->precision_value < ft_strlen(NULL_STR))
			s = EMPTY_STR;
	}
	f->pad = ' ';
	return (create_str_to_print(s, f, ft_strlen(s)));
}

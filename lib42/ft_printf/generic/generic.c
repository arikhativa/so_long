/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:05:38 by yoav              #+#    #+#             */
/*   Updated: 2022/06/26 18:41:46 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "flag.h"
#include "printable_mem.h"

size_t	get_smaller(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

size_t	get_bigger(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	generic_get_start(t_flag *f, size_t mem_size, size_t digit, size_t pad)
{
	if (f->left_adjusted)
		return (0);
	digit = get_bigger(f->precision_value, digit);
	return (mem_size - digit - pad);
}

size_t	get_size_for_number(t_flag *f, size_t digit, size_t pad)
{
	size_t	size;

	size = get_bigger(f->width, (digit + pad));
	size = get_bigger((f->precision_value + pad), size);
	return (size);
}

size_t	add_precision_pad(char *ret, size_t pos, t_flag *f, size_t nbr_len)
{
	size_t	i;

	i = 0;
	while (f->precision_value > (nbr_len + i))
	{
		ret[pos + i] = '0';
		++i;
	}
	return (pos + i);
}

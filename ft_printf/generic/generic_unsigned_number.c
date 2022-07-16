/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_unsigned_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/26 18:12:50 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "convert.h"
#include "count.h"
#include "generic.h"
#include "base.h"

static int	get_pad(t_flag *f)
{
	if (f->hash)
		return (2);
	return (0);
}

static size_t	add_pad_if_needed(t_flag *f, size_t start, char *ret)
{
	size_t	len;

	len = 0;
	if (f->hash && f->is_upper)
	{
		len = ft_strlen(HEX_MARK_UPPER);
		ft_memcpy((ret + start), HEX_MARK_UPPER, len);
	}
	else if (f->hash)
	{
		len = ft_strlen(HEX_MARK_LOWER);
		ft_memcpy((ret + start), HEX_MARK_LOWER, len);
	}
	return (start + len);
}

t_printable_mem	*convert_generic_unsigned_number(size_t nbr, t_flag *f, \
													char *base)
{
	t_printable_mem	*ret;
	size_t			digit;
	size_t			i;
	size_t			pad;
	size_t			size;

	digit = count_digit_by_base_unsigned(nbr, ft_strlen(base));
	pad = get_pad(f);
	size = get_size_for_number(f, digit, pad);
	ret = create_printable_mem(f, size);
	if (!ret)
		return (NULL);
	i = generic_get_start(f, size, digit, pad);
	i = add_pad_if_needed(f, i, ret->mem);
	i = add_precision_pad(ret->mem, i, f, digit);
	stoa_base(nbr, base, (ret->mem + i), digit);
	return (ret);
}

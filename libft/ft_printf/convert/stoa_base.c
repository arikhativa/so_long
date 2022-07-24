/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:47:44 by yoav              #+#    #+#             */
/*   Updated: 2022/06/20 13:59:27 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

static void	rec(size_t n, size_t base, char *base_str, char *ret)
{
	if (n / base)
	{
		rec(n / base, base, base_str, ret - 1);
		rec(n % base, base, base_str, ret);
	}
	if (n < base)
		*ret = base_str[n];
}

void	stoa_base(size_t n, char *base_str, char *ret, size_t digit)
{
	size_t	base;

	base = (size_t)ft_strlen(base_str);
	rec(n, base, base_str, (ret + digit - 1));
}

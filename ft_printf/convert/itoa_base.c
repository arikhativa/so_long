/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:47:44 by yoav              #+#    #+#             */
/*   Updated: 2022/06/23 16:40:09 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

static void	rec(long n, long base, char *base_str, char *ret)
{
	if (n / base)
	{
		rec(n / base, base, base_str, ret - 1);
		rec(n % base, base, base_str, ret);
	}
	if (n < base)
		*ret = base_str[n];
}

void	itoa_base(long n, char *base_str, char *ret, size_t digit)
{
	long	base;

	base = (long)ft_strlen(base_str);
	if (0 > n)
		n *= -1;
	rec(n, base, base_str, (ret + digit - 1));
}

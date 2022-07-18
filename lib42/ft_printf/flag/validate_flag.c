/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:45:05 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 15:31:01 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "flag.h"
#include "define.h"

int	is_flag_valid(const char *s)
{
	t_flag	f;

	ft_bzero(&f, sizeof(t_flag));
	if (!s || !*(s + 1))
		return (FALSE);
	++s;
	while (ft_strchr(ALL_FLAGS, *s))
		++s;
	while (ft_isdigit(*s))
		++s;
	if (*s == '.')
	{
		++s;
		while (ft_isdigit(*s))
			++s;
	}
	return (is_handler_char(*s));
}

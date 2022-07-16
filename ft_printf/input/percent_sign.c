/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:04:31 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 14:03:17 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include "input.h"
#include "flag.h"

const char	*skip_escp(const char *s)
{
	if (*s == SEP_CHAR)
	{
		++s;
		while (ft_isdigit(*s) || ft_strchr(ALL_FLAGS, *s) || '.' == *s)
			++s;
	}
	return (s);
}

int	is_escp(const char *s)
{
	if (!s || !*s)
		return (FALSE);
	if (*s == SEP_CHAR)
	{
		++s;
		while (ft_isdigit(*s) || ft_strchr(ALL_FLAGS, *s) || '.' == *s)
			++s;
		return (*s == SEP_CHAR);
	}
	return (FALSE);
}

int	is_flag(const char *s)
{
	if (!s || !*s)
		return (FALSE);
	if (*s == SEP_CHAR && is_flag_valid(s))
		return (TRUE);
	return (FALSE);
}

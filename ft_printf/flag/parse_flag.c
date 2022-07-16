/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:08:57 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 10:11:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "flag.h"
#include "define.h"

int	is_handler_char(char c)
{
	return (ft_strchr(SUPPORTED_TYPES, c) != NULL);
}

const char	*skip_flag(const char *s)
{
	while (*s && !is_handler_char(*s))
		++s;
	if (!*s)
		return (s);
	return (s + 1);
}

const char	*parse_flag(const char *s, t_flag *f)
{
	f->pad = ' ';
	while (ft_strchr(ALL_FLAGS, *s))
	{
		if (' ' == *s)
			f->space = TRUE;
		else if ('#' == *s)
			f->hash = TRUE;
		else if ('0' == *s)
			f->pad = '0';
		else if ('+' == *s)
			f->plus = TRUE;
		else if ('-' == *s)
			f->left_adjusted = TRUE;
		++s;
	}
	if (f->left_adjusted)
		f->pad = ' ';
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 10:46:08 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 11:21:02 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "flag.h"
#include "define.h"

static const char	*get_width(const char *s, t_flag *f)
{
	if ('.' == *s)
		return (s);
	f->width = ft_atoi(s);
	while (ft_isdigit(*s))
		++s;
	return (s);
}

static const char	*get_conversion(const char *s, t_flag *f)
{
	f->conversion = *s;
	return (s + 1);
}

static const char	*get_precision(const char *s, t_flag *f)
{
	if ('.' == *s)
	{
		++s;
		f->is_precision = TRUE;
		f->precision_value = ft_atoi(s);
		f->pad = ' ';
		while (ft_isdigit(*s))
			++s;
	}
	return (s);
}

const char	*get_flag(const char *s, t_flag *f)
{
	ft_bzero(f, sizeof(t_flag));
	s = parse_flag(s, f);
	s = get_width(s, f);
	s = get_precision(s, f);
	s = get_conversion(s, f);
	return (s);
}

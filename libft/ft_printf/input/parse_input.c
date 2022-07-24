/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:50:32 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 14:11:02 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

#include "libft.h"
#include "define.h"
#include "printable_mem.h"
#include "flag.h"
#include "list.h"
#include "input.h"

const char	*skip_normal_str(const char *s)
{
	while (*s)
	{
		if (is_flag(s))
			break ;
		if (is_escp(s))
			s = skip_escp(s);
		++s;
	}
	if (is_flag(s))
		++s;
	return (s);
}

size_t	count_normal_char_len(const char *s)
{
	size_t	c;

	c = 0;
	while (*s)
	{
		if (is_flag(s))
			s = skip_flag(s);
		else if (is_escp(s))
		{
			s = skip_escp(s) + 1;
			++c;
		}
		else
		{
			++s;
			++c;
		}
	}
	return (c);
}

int	parse_input(const char *input, t_list **node, va_list list)
{
	t_flag			flag;
	t_printable_mem	*m;

	m = NULL;
	input = skip_normal_str(input);
	while (*input)
	{
		input = get_flag(input, &flag);
		m = convert_input_to_mem(list, &flag);
		if (NULL == m)
			return (ERROR);
		if (add_param_to_list(node, m) == ERROR)
			return (ERROR);
		input = skip_normal_str(input);
	}
	return (SUCCESS);
}

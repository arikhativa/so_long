/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:13:38 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 14:08:19 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "flag.h"
#include "input.h"
#include "define.h"
#include "libft.h"
#include "printable_mem.h"

static void	cpy_from_input(char **dest, const char **input)
{
	const char	*s;
	char		*d;

	s = *input;
	d = *dest;
	while (*s)
	{
		if (is_flag(s))
			break ;
		if (is_escp(s))
			s = skip_escp(s);
		*d = *s;
		++d;
		++s;
	}
	*dest = (d);
	*input = skip_flag(s);
}

static void	cpy_from_list(char **dest, t_list **list)
{
	int		i;

	if (!*list)
		return ;
	i = cpy_printable_mem(*dest, (*list)->content);
	*list = (*list)->next;
	*dest = (*dest + i);
}

static char	*create_string(const char *input, t_list *list, size_t len)
{
	char	*ret;
	char	*runner;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	runner = ret;
	while (*input)
	{
		cpy_from_input(&runner, &input);
		cpy_from_list(&runner, &list);
	}
	return (ret);
}

int	print_all(char *input, t_list *list)
{
	char	*s;
	size_t	len;

	len = count_normal_char_len(input);
	len += count_all_printable_mem_len(list);
	s = create_string(input, list, len);
	if (!s)
		return (ERROR);
	write(1, s, len);
	free(s);
	return (len);
}

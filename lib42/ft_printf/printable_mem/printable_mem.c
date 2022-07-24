/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:25:16 by yoav              #+#    #+#             */
/*   Updated: 2022/06/26 18:37:05 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "flag.h"
#include "handler.h"
#include "printable_mem.h"

t_printable_mem	*convert_input_to_mem(va_list l, t_flag *flag)
{
	if ('c' == flag->conversion)
		return (handle_char(l, flag));
	else if ('s' == flag->conversion)
		return (handle_str(l, flag));
	else if ('d' == flag->conversion)
		return (handle_dec(l, flag));
	else if ('x' == flag->conversion)
		return (handle_hax_lower(l, flag));
	else if ('X' == flag->conversion)
		return (handle_hax_upper(l, flag));
	else if ('i' == flag->conversion)
		return (handle_dec(l, flag));
	else if ('u' == flag->conversion)
		return (handle_unsigned_dec(l, flag));
	else if ('p' == flag->conversion)
		return (handle_ptr(l, flag));
	return (NULL);
}

size_t	cpy_printable_mem(char *d, t_printable_mem *m)
{
	size_t	i;

	if (!m)
		return (0);
	i = 0;
	while (i < m->size)
	{
		d[i] = m->mem[i];
		++i;
	}
	return (i);
}

void	free_printable_mem(void *content)
{
	t_printable_mem	*m;

	m = (t_printable_mem *)content;
	free(m->mem);
	m->mem = NULL;
	m->size = 0;
	free(m);
}

size_t	count_all_printable_mem_len(t_list *list)
{
	t_printable_mem	*m;
	size_t			c;

	c = 0;
	while (list)
	{
		m = list->content;
		c += m->size;
		list = list->next;
	}
	return (c);
}

t_printable_mem	*create_printable_mem(t_flag *f, size_t size)
{
	t_printable_mem	*ret;

	ret = (t_printable_mem *)malloc(sizeof(t_printable_mem));
	if (ret)
	{
		ret->mem = (char *)malloc(sizeof(char) * (size + 1));
		if (!ret->mem)
		{
			free(ret);
			return (NULL);
		}
		ft_memset(ret->mem, f->pad, size);
		ret->mem[size] = '\0';
		ret->size = size;
	}
	return (ret);
}

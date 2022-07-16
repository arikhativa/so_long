/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:04:29 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 10:21:33 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object.h"
#include "map.h"
#include "define.h"

static inline int	is_height_valid(int	height)
{
	return (MIN_HEIGHT_LEN <= height);
}

int	is_topbot_line_chars_valid(const char *line, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (WALL_CHAR != line[i])
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int	is_mid_line_chars_valid(const char *line, int size)
{
	int	i;

	if (WALL_CHAR != line[0] || WALL_CHAR != line[size - 1])
		return (FALSE);
	i = 0;
	while (i < size)
	{
		if (!ft_strchr(VALID_CHARS, line[i]))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int	map_validate(t_map *m)
{
	int	i;

	if (is_height_valid(m->size->y))
		return (BAD_HEIGHT);
	m->size->x = get_line_size(m->tab[0]);
	if (!is_first_line_size_valid(m->size->x))
		return (BAD_SIZE_TOP);
	if (!is_topbot_line_chars_valid(m->tab[0], m->size->x))
		return (BAD_CHAR_TOP);
	i = 1;
	while (i < (m->size->y - 1))
	{
		if (!is_mid_line_size_valid(m->tab[i], m->size->x))
			return (BAD_SIZE_MID);
		if (!is_mid_line_chars_valid(m->tab[i], m->size->x))
			return (BAD_CHAR_MID);
		++i;
	}
	if (!is_mid_line_size_valid(m->tab[m->size->y - 1], m->size->x))
			return (BAD_SIZE_BOTTOM);
	if (!is_topbot_line_chars_valid(m->tab[m->size->y - 1], m->size->x))
		return (BAD_CHAR_BOTTOM);
	return (SUCCESS);
}
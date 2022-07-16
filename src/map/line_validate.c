/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:20:59 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 10:55:36 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"

int	get_line_size(char *line)
{
	int	i;

	i = 0;
	while (line[i] && NEW_LINE != line[i])
		++i;
	return (i);
}

int	is_first_line_size_valid(int len)
{
	return (MIN_WIDTH_LEN <= len);
}

int	is_mid_line_size_valid(char *line, int first_line_len)
{
	int	new_len;

	new_len = get_line_size(line);
	return (new_len == first_line_len);
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

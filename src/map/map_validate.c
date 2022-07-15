/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:04:29 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 13:17:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"

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


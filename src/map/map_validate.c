/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <files.associations>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:04:29 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 13:07:43 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object.h"
#include "map.h"
#include "define.h"

static inline int	is_height_valid(int height)
{
	return (MIN_HEIGHT_LEN <= height);
}

int	map_validate_size_cnd_char(t_map *m)
{
	int	i;

	if (!is_height_valid(m->size->y))
		return (ERROR_HEIGHT);
	m->size->x = get_line_size(m->tab[0]);
	if (!is_first_line_size_valid(m->size->x))
		return (ERROR_SIZE_TOP);
	if (!is_topbot_line_chars_valid(m->tab[0], m->size->x))
		return (ERROR_CHAR_TOP);
	i = 1;
	while (i < (m->size->y - 1))
	{
		if (!is_mid_line_size_valid(m->tab[i], m->size->x))
			return (ERROR_SIZE_MID);
		if (!is_mid_line_chars_valid(m->tab[i], m->size->x))
			return (ERROR_CHAR_MID);
		++i;
	}
	if (!is_mid_line_size_valid(m->tab[m->size->y - 1], m->size->x))
		return (ERROR_SIZE_BOTTOM);
	if (!is_topbot_line_chars_valid(m->tab[m->size->y - 1], m->size->x))
		return (ERROR_CHAR_BOTTOM);
	return (SUCCESS);
}

int	map_validate(t_map *m)
{
	int	stt;

	stt = map_validate_size_cnd_char(m);
	if (SUCCESS != stt)
		return (stt);
	stt = map_validate_special_char(m);
	if (SUCCESS != stt)
		return (stt);
	return (SUCCESS);
}

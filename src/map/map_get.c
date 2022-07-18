/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:40:21 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:10:48 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"
#include "object.h"

t_point	map_get_size(t_meta *m)
{
	return (m->map->size);
}

char	map_get_char(t_meta *m, t_point pos)
{
	return (tab_get_char(m->map->tab, pos));
}

int	map_count_collect(t_meta *m)
{
	int		ret;
	int		y;
	int		x;
	char	**tab;

	tab = m->map->tab;
	y = 0;
	ret = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (COLLECT_CHAR == tab[y][x])
				++ret;
			++x;	
		}
		++y;
	}
	return (ret);
}
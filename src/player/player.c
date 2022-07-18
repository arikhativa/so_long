/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:38:22 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:38:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "point.h"
#include "player.h"
#include "object.h"

// TODO make generic
static void	find_player_pos_in_map(t_meta *m)
{
	char	**tab;
	int		x;
	int		y;

	tab = m->map->tab;
	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == PLAYER_CHAR)
			{
				player_set_pos(m, point_set(x, y));
				return ;
			}
			++x;
		}
		++y;
	}
}

int player_create(t_meta *m)
{
	m->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!m->player)
		return (ERROR_PLAYER_CREATE);
	find_player_pos_in_map(m);
	m->player->is_enable = TRUE;
	return (SUCCESS);
}

void	player_free(t_player *p)
{
	free(p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <files.associations>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:38:22 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 14:11:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "point.h"
#include "object.h"

// TODO make generic
void	find_player_pos_in_map(t_meta *m, t_point *pos)
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
				pos->x = x;
				pos->y = y;
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
	m->player->pos = point_create();
	if (!m->player->pos)
	{
		free(m->player);
		// TODO make sure m free is safe - maybe bzero in main
		m->player = NULL;
		return (ERROR_PLAYER_CREATE);
	}
	find_player_pos_in_map(m, m->player->pos);
	return (SUCCESS);
}

void	player_free(t_player *p)
{
	point_free(p->pos);
	p->pos = NULL;
	free(p);
}

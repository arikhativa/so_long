/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:12:56 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:15:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "lib42.h"
#include "map.h"

static void	remove_player_if_needed(int *should_remove, char *ptr)
{
	if (FALSE == *should_remove && PLAYER_CHAR == *ptr)
	{
		*should_remove = TRUE;
		return ;
	}
	if (TRUE == *should_remove && PLAYER_CHAR == *ptr)
		*ptr = EMPTY_CHAR;
}

void	map_clean_player(t_map *m)
{
	int		remove_player;
	int		y;
	int		x;
	char	**tab;

	tab = m->tab;
	y = 0;
	remove_player = FALSE;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			remove_player_if_needed(&remove_player, &(tab[y][x]));
			++x;
		}
		++y;
	}
}

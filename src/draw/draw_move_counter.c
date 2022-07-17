/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:07:30 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 11:39:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "object.h"
#include "player.h"
#include "libft.h"
#include "point.h"
#include "map.h"
#include "draw.h"
#include "define.h"

void	draw_init_move_counter(t_meta *m)
{
	mlx_string_put(m->mlx,
					m->win->ref,
					0,
					0,
					MOVE_COUNTER_COLOR,
					MOVE_COUNTER_TEXT);
}

void	draw_clear_move_counter(t_meta *m)
{
	t_point *map_size;
	t_point pos;
	int		i;

	map_size = map_get_size(m);
	i = 0;
	while (i < map_size->x)
	{
		point_set(&pos, MOVE_COUNTER_X + i, 0);
		draw_reset_pos(m, &pos);
		++i;
	}
}

void	draw_move_counter(t_meta *m)
{
	char *str;

	str = ft_itoa(player_get_move_counter(m));
	draw_clear_move_counter(m);
	mlx_string_put(m->mlx,
					m->win->ref,
					MOVE_COUNTER_X * IMG_SIZE,
					0,
					MOVE_COUNTER_COLOR,
					str);
	free(str);
}


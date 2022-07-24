/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:07:30 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:15:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "object.h"
#include "player.h"
#include "lib42.h"
#include "point.h"
#include "map.h"
#include "draw.h"
#include "meta.h"
#include "define.h"

void	draw_init_move_counter(t_meta *m)
{
	mlx_string_put(meta_get_mlx(m), \
		meta_get_win(m), \
		0, \
		0, \
		MOVE_COUNTER_COLOR, \
		MOVE_COUNTER_TEXT);
}

void	draw_clear_move_counter(t_meta *m)
{
	t_point	map_size;
	t_point	pos;
	int		i;

	map_size = map_get_size(m);
	i = 0;
	while (i < map_size.x)
	{
		pos = point_set(MOVE_COUNTER_X + i, 0);
		draw_reset_pos(m, pos);
		++i;
	}
}

void	draw_move_counter(t_meta *m)
{
	char	*str;

	str = ft_itoa(player_get_move_counter(m));
	draw_clear_move_counter(m);
	mlx_string_put(meta_get_mlx(m), \
		meta_get_win(m), \
		MOVE_COUNTER_X * IMG_SIZE, \
		0, \
		0x55f44fff, \
		str);
	free(str);
}

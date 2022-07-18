/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:19:14 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:21:00 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "point.h"
#include "image.h"
#include "define.h"
#include "map.h"
#include "object.h"
#include "draw.h"

void	draw_map(t_meta *m)
{
	t_point pos;
	int	y;
	int	x;

	y = 0;
	while (y < m->map->size.y)
	{
		x = 0;
		while (x < m->map->size.x)
		{
			pos = point_set(x, y);
			draw_by_char(m, pos, map_get_char(m, pos));
			++x;
		}
		y++;
	}
	draw_init_move_counter(m);
	draw_move_counter(m);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:19:14 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 17:33:57 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "point.h"
#include "image.h"
#include "define.h"
#include "object.h"

void	draw_wall(t_meta *m, t_point *pos)
{
	mlx_put_image_to_window(m->mlx, m->win->ref,
		get_image(m, WALL_I), pos->x, pos->y);
}

void	draw_map(t_meta *m)
{
	t_point pos;
	int	y;
	int	x;

	y = 0;
	while (y < m->map->size->y)
	{
		x = 0;
		while (x < m->map->size->x)
		{
			draw_wall(m, point_set(&pos, x * IMG_SIZE, y * IMG_SIZE));
			++x;
		}
		y++;
	}
}

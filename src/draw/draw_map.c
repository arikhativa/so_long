/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:19:14 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 18:05:46 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "point.h"
#include "image.h"
#include "define.h"
#include "map.h"
#include "object.h"

void	draw_image(t_meta *m, t_point *pos, int image_index)
{
	mlx_put_image_to_window(m->mlx, m->win->ref,
		get_image(m, image_index), pos->x * IMG_SIZE, pos->y * IMG_SIZE);
}

void	draw_by_char(t_meta *m, t_point *pos, char c)
{
	if (PLAYER_CHAR == c)
		draw_image(m, pos, PLAYER_I);
	else if (COLLECT_CHAR == c)
		draw_image(m, pos, COLLECT_I);
	else if (EXIT_CHAR == c)
		draw_image(m, pos, EXIT_I);
	else if (WALL_CHAR == c)
		draw_image(m, pos, WALL_I);
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
			point_set(&pos, x, y);
			draw_by_char(m, &pos, map_get_char(m, &pos));
			++x;
		}
		y++;
	}
}

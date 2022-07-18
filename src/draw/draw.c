/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:12:33 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 18:15:35 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "define.h"
#include "meta.h"
#include "point.h"
#include "image.h"
#include "mlx.h"

void	draw_reset_pos(t_meta *m, t_point pos)
{
	mlx_put_image_to_window(meta_get_mlx(m), meta_get_win(m),
		get_image(m, EMPTY_I), pos.x * IMG_SIZE, pos.y * IMG_SIZE);
}

void	draw_image(t_meta *m, t_point pos, int image_index)
{
	draw_reset_pos(m, pos);
	mlx_put_image_to_window(meta_get_mlx(m), meta_get_win(m),
		get_image(m, image_index), pos.x * IMG_SIZE, pos.y * IMG_SIZE);
}

void	draw_reset_on_map(t_meta *m, t_point pos)
{
	t_point tmp;

	tmp = point_move_down(pos);
	draw_reset_pos(m, tmp);
}

void	draw_on_map(t_meta *m, t_point pos, int image_index)
{
	t_point tmp;

	tmp = point_move_down(pos);
	draw_image(m, tmp, image_index);
}

void	draw_by_char(t_meta *m, t_point pos, char c)
{
	if (PLAYER_CHAR == c)
		draw_on_map(m, pos, PLAYER_I);
	else if (COLLECT_CHAR == c)
		draw_on_map(m, pos, COLLECT_I);
	else if (EXIT_CHAR == c)
		draw_on_map(m, pos, EXIT_I);
	else if (WALL_CHAR == c)
		draw_on_map(m, pos, WALL_I);
}

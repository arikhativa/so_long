/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:12:33 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 18:25:43 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "define.h"
#include "image.h"
#include "mlx.h"

void	draw_reset_pos(t_meta *m, t_point *pos)
{
	mlx_put_image_to_window(m->mlx, m->win->ref,
		get_image(m, EMPTY_I), pos->x * IMG_SIZE, pos->y * IMG_SIZE);
}

void	draw_image(t_meta *m, t_point *pos, int image_index)
{
	draw_reset_pos(m, pos);
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

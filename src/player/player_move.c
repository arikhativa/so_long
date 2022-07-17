/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:22:02 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 10:21:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "player.h"
#include "point.h"
#include "draw.h"

void	player_remove_old_pos(t_meta *m)
{
	t_point *p;

	p = player_get_pos(m);
	draw_reset_pos(m, player_get_pos(m));
}

void	player_move(t_meta *m, t_point *new_pos)
{
	player_remove_old_pos(m);
	player_set_pos(m, new_pos);
	draw_image(m, new_pos, PLAYER_I);
}

void	player_eval_up(t_meta *m)
{
	t_point	new_pos;

	point_copy(&new_pos, player_get_pos(m));
	
	point_move_up(&new_pos);

	player_move(m, &new_pos);
}

void	player_eval_down(t_meta *m)
{
	t_point	new_pos;

	point_copy(&new_pos, player_get_pos(m));
	
	point_move_down(&new_pos);

	player_move(m, &new_pos);
}

void	player_eval_left(t_meta *m)
{
	t_point	new_pos;

	point_copy(&new_pos, player_get_pos(m));
	
	point_move_left(&new_pos);

	player_move(m, &new_pos);
}

void	player_eval_right(t_meta *m)
{
	t_point	new_pos;

	point_copy(&new_pos, player_get_pos(m));
	
	point_move_right(&new_pos);

	player_move(m, &new_pos);
}
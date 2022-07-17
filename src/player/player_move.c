/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:22:02 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 11:33:25 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "player.h"
#include "point.h"
#include "draw.h"
#include "map.h"

void	player_remove_old_pos(t_meta *m)
{
	t_point *p;

	p = player_get_pos(m);
	draw_reset_on_map(m, player_get_pos(m));
}

void	player_move(t_meta *m, t_point *new_pos)
{
	player_remove_old_pos(m);
	player_set_pos(m, new_pos);
	draw_on_map(m, new_pos, PLAYER_I);
	player_update_move_counter(m);
}

void	player_eval(t_meta *m, t_point_move point_move_func)
{
	t_point	new_pos;

	point_copy(&new_pos, player_get_pos(m));
	point_move_func(&new_pos);
	if (map_is_wall(m, &new_pos))
		return ;
	player_move(m, &new_pos);
}

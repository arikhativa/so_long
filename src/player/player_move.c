/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:22:02 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 18:57:10 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "player.h"
#include "draw.h"

void	player_remove_old_pos(t_meta *m)
{
	t_point *p;

	p = player_get_pos(m);
	draw_reset_pos(m, player_get_pos(m));
}

void	player_update_pos(int key, t_meta *m)
{
	if  (KEY_DOWN == key)
		player_down(m);
	else if  (KEY_UP == key)
		player_up(m);
	else if  (KEY_LEFT == key)
		player_left(m);
	else if  (KEY_RIGHT == key)
		player_right(m);
}

void	player_move(int key, t_meta *m)
{
	player_remove_old_pos(m);
	player_update_pos(key, m);
	draw_image(m, player_get_pos(m), PLAYER_I);
}

void	player_eval(int key, t_meta *m)
{
	player_move(key, m);
}

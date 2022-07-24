/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:32:56 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:59:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "point.h"

void	player_set_pos(t_meta *m, t_point new_pos)
{
	m->player->pos = point_copy(new_pos);
}

void	player_inc_move_counter(t_meta *m)
{
	++m->player->move_counter;
}

void	player_disable(t_meta *m)
{
	m->player->is_enable = FALSE;
}

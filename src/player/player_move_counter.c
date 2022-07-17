/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_counter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:42:48 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 11:19:19 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "player.h"
#include "draw.h"

void	player_update_move_counter(t_meta *m)
{
	player_inc_move_counter(m);
	draw_move_counter(m);
}

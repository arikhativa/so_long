/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:32:56 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 10:16:28 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "point.h"
#include "player.h"

void	player_set_pos(t_meta *m, t_point *new_pos)
{
	point_copy(player_get_pos(m), new_pos);
}

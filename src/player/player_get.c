/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:26:00 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:11:32 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"

t_point	player_get_pos(t_meta *m)
{
	return (m->player->pos);
}

int	player_get_move_counter(t_meta *m)
{
	return (m->player->move_counter);
}

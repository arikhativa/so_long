/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:32:56 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 18:34:20 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	player_down(t_meta *m)
{
	++m->player->pos->y;
}

void	player_up(t_meta *m)
{
	--m->player->pos->y;
}

void	player_left(t_meta *m)
{
	--m->player->pos->x;
}

void	player_right(t_meta *m)
{
	++m->player->pos->x;
}

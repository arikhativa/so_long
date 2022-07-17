/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_finish_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:56:58 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 16:00:38 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "object.h"
#include "player.h"
#include "libft.h"
#include "point.h"
#include "map.h"
#include "draw.h"
#include "define.h"

void	draw_finish_game(t_meta *m)
{
	mlx_string_put(m->mlx,
					m->win->ref,
					END_MSG_I * IMG_SIZE,
					0,
					MOVE_COUNTER_COLOR,
					"Done! press 'esc' to exit :)");
}
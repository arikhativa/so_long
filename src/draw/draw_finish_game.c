/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_finish_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:56:58 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:51:59 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "object.h"
#include "meta.h"
#include "define.h"

void	draw_finish_game(t_meta *m)
{
	mlx_string_put(meta_get_mlx(m), \
					meta_get_win(m), \
					END_MSG_I * IMG_SIZE, \
					0, \
					MOVE_COUNTER_COLOR, \
					"Done! press 'esc' to exit :)");
}

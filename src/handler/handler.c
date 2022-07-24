/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:15:29 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:54:18 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "point.h"
#include "meta.h"
#include "define.h"
#include "player.h"
#include "object.h"

int	handler_close(t_meta *m)
{
	meta_free(m);
	exit(SUCCESS);
	return (SUCCESS);
}

int	handler_key_press(int key, t_meta *m)
{
	if (ESC == key)
		handler_close(m);
	else if (KEY_UP == key)
		player_eval(m, point_move_up);
	else if (KEY_DOWN == key)
		player_eval(m, point_move_down);
	else if (KEY_LEFT == key)
		player_eval(m, point_move_left);
	else if (KEY_RIGHT == key)
		player_eval(m, point_move_right);
	return (SUCCESS);
}

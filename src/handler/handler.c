/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:15:29 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 16:34:17 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "point.h"
#include "define.h"
#include "player.h"
#include "object.h"

int	handler_close(int key, t_meta *m)
{
	printf("close\n");
	// TODO does not work for some reason
	// meta_free(m);
	// system("leaks so_long");
	exit(0);
}

int	handler_key_press(int key, t_meta *m)
{
	if (ESC == key)
		handler_close(key, m);
	else if  (KEY_UP == key)
		player_eval(m, point_move_up);
	else if  (KEY_DOWN == key)
		player_eval(m, point_move_down);
	else if  (KEY_LEFT == key)
		player_eval(m, point_move_left);
	else if  (KEY_RIGHT == key)
		player_eval(m, point_move_right);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:15:29 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 10:21:51 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "define.h"
#include "player.h"
#include "object.h"

int	handler_close(int keycode, t_meta *m)
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
	else if  (KEY_DOWN == key)
		player_eval_down(m);
	else if  (KEY_UP == key)
		player_eval_up(m);
	else if  (KEY_LEFT == key)
		player_eval_left(m);
	else if  (KEY_RIGHT == key)
		player_eval_right(m);
	return (1);
}

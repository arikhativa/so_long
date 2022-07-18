/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:28:22 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:25:03 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "object.h"

t_point	player_get_pos(t_meta *m);
int player_create(t_meta *m);
void	player_free(t_player *p);

t_point	player_get_pos(t_meta *m);
void	player_set_pos(t_meta *m, t_point new_pos);

void	player_eval(t_meta *m, t_point_move point_move_func);

void	player_inc_move_counter(t_meta *m);
void	player_update_move_counter(t_meta *m);
int		player_get_move_counter(t_meta *m);
void	player_disable(t_meta *m);

#endif

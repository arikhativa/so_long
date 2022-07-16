/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:28:22 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 18:52:09 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "object.h"

void	player_eval(int key, t_meta *m);

t_point	*player_get_pos(t_meta *m);
int player_create(t_meta *m);
void	player_free(t_player *p);

t_point	*player_get_pos(t_meta *m);

void	player_down(t_meta *m);
void	player_up(t_meta *m);
void	player_left(t_meta *m);
void	player_right(t_meta *m);

#endif

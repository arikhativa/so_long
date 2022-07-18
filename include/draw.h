/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:28:24 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:17:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#include "object.h"

void	draw_map(t_meta *m);
void	draw_image(t_meta *m, t_point pos, int image_index);
void	draw_by_char(t_meta *m, t_point pos, char c);
void	draw_reset_pos(t_meta *m, t_point pos);

void	draw_init_move_counter(t_meta *m);
void	draw_move_counter(t_meta *m);
void	draw_finish_game(t_meta *m);

void	draw_reset_on_map(t_meta *m, t_point pos);
void	draw_on_map(t_meta *m, t_point pos, int image_index);

#endif

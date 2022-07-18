/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:50:41 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:28:59 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "object.h"

t_point point_copy(t_point p);
t_point point_set(int x, int y);

t_point	point_move_up(t_point p);
t_point	point_move_down(t_point p);
t_point	point_move_left(t_point p);
t_point	point_move_right(t_point p);

#endif

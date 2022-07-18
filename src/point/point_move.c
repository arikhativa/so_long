/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:07:12 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:23:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_point	point_move_up(t_point p)
{
	--p.y;
	return (p);
}

t_point	point_move_down(t_point p)
{
	++p.y;
	return (p);
}

t_point	point_move_left(t_point p)
{
	--p.x;
	return (p);
}

t_point	point_move_right(t_point p)
{
	++p.x;
	return (p);
}

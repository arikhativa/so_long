/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:07:12 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 10:08:30 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	point_move_up(t_point *p)
{
	--p->y;
}

void	point_move_down(t_point *p)
{
	++p->y;
}

void	point_move_left(t_point *p)
{
	--p->x;
}

void	point_move_right(t_point *p)
{
	++p->x;
}

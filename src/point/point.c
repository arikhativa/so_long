/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:05:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:15:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "lib42.h"
#include "point.h"

t_point	point_copy(t_point p)
{
	t_point	ret;

	ret.x = p.x;
	ret.y = p.y;
	return (ret);
}

t_point	point_set(int x, int y)
{
	t_point	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

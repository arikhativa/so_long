/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:05:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 15:34:33 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "point.h"

t_point	*point_create(void)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	if (!p)
		return (NULL);
	return (p);
}

t_point	*point_create_set(int x, int y)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	if (!p)
		return (NULL);
	point_set(p, x, y);
	return (p);
}

void	point_free(t_point *p)
{
	p->x = 0;
	p->y = 0;
	free(p);
}

void	point_set(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
}
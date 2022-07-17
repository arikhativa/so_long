/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:10:31 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 10:21:20 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "point.h"
#include "object.h"

t_point	*point_copy(t_point *d, t_point *s)
{
	d->x = s->x;
	d->y = s->y;
	return (d);
}

t_point	*point_create_copy(t_point *p)
{
	t_point	*new;

	new = point_create();
	if (!new)
		return (NULL);
	point_set(new, p->x, p->y);
	return (new);
}

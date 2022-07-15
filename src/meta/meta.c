/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:21:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 19:32:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "object.h"
#include "input.h"
#include "sprite.h"
#include "window.h"
#include "map.h"
#include "point.h"
#include "meta.h"
#include "libft.h"

static inline int	meta_create_1(t_meta *m, int fd, char *name, t_point *p)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		return (ERROR);
	m->win = window_create(m->mlx, p->x, p->y, name);
	if (!m->win)
		return (ERROR);
	m->sprite = sprite_create_and_load(meta_get_mlx(m));
	if (!m->sprite)
		return (ERROR);
	m->map = input_create_map(fd);
	if (!m->map)
		return (ERROR);
	return (SUCCESS);
}

t_meta	*meta_create(int width, int height, char *name, int fd)
{
	t_meta	*m;
	t_point p;
	int		stt;

	m = (t_meta *)ft_calloc(1, sizeof(t_meta));
	if (!m)
		return (NULL);
	point_set(&p, width, height);
	stt = meta_create_1(m, fd, name, &p);
	if (SUCCESS != stt)
	{
		meta_free(m);
		return (NULL);
	}
	return (m);
}

void	meta_free(t_meta *m)
{
	if (!m)
		return ;
	if (m->win)
		window_free(m->win, m->mlx);
	if (m->sprite)
		sprite_free(m->sprite, m->mlx);
	if (m->map)
		map_free(m->map);
	free(m);
}

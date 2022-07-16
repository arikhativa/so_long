/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:21:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 16:57:37 by yrabby           ###   ########.fr       */
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

int meta_init(t_meta *m, t_point *p, char *name, int fd)
{
	int		stt;

	stt = meta_create_1(m, fd, name, p);
	if (SUCCESS != stt)
	{
		meta_free(m);
		return (ERROR);
	}
	return (SUCCESS);
}

void	meta_free(t_meta *m)
{
	if (m->win)
		window_free(m->win, m->mlx);
	if (m->sprite)
		sprite_free(m->sprite, m->mlx);
	if (m->map)
		map_free(m->map);
}

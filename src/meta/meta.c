/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:21:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 16:08:52 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "object.h"
#include "input.h"
#include "sprite.h"
#include "window.h"
#include "map.h"
#include "meta.h"

static inline int	meta_create_2(t_meta *m, int fd)
{
	m->sprite = sprite_create_and_load(meta_get_mlx(m));
	if (!m->sprite)
		return (ERROR);
	m->map = input_create_map(fd);
	if (!m->map)
		return (ERROR);
	return (SUCCESS);
}

static inline int meta_create_1(t_meta *m, int width, int height, char *name)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		return (ERROR);
	m->win = window_create(m->mlx, width, height, name);
	if (!m->win)
		return (ERROR);
	return (SUCCESS);
}

t_meta	*meta_create(int width, int height, char *name, int fd)
{
	t_meta	*m;
	int		stt;

	m = (t_meta *)malloc(sizeof(t_meta));
	if (!m)
		return (NULL);
	stt = meta_create_1(m, width, height, name);
	stt += meta_create_2(m, fd);
	if (SUCCESS != stt)
	{
		meta_free(m);
		return (NULL);
	}
	return (m);
}

void	meta_free(t_meta *m)
{
	if (m->win)
		window_free(m->win);
	if (m->sprite)
		sprite_free(m->sprite);
	if (m->map)
		map_free(m->map);
	free(m);
}

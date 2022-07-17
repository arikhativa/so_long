/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <files.associations>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:21:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 13:09:57 by yrabby           ###   ########.fr       */
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
#include "error.h"
#include "player.h"
#include "libft.h"

// TODO add err codes 
static inline int	meta_create_1(t_meta *m, int fd)
{
	int	stt;

	m->map = input_create_map(fd);
	if (!m->map)
		return (ERROR_MAP_CREATE);
	stt = map_validate(m->map);
	if (SUCCESS != stt)
		return (stt);
	stt = player_create(m);
	if (SUCCESS != stt)
		return (stt);
	m->mlx = mlx_init();
	if (!m->mlx)
		return (ERROR);
	m->win = window_create(m->mlx, map_get_size(m));
	if (!m->win)
		return (ERROR);
	m->sprite = sprite_create_and_load(meta_get_mlx(m));
	if (!m->sprite)
		return (ERROR);
	return (SUCCESS);
}

int meta_init(t_meta *m, int fd)
{
	int		stt;

	stt = meta_create_1(m, fd);
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
	if (m->player)
		player_free(m->player);
}

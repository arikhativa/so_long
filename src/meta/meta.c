/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:21:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 19:13:19 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "object.h"
#include "input.h"
#include "sprite.h"
#include "map.h"
#include "point.h"
#include "meta.h"
#include "error.h"
#include "player.h"
#include "collect.h"
#include "hook.h"
#include "draw.h"
#include "libft.h"

static inline int	meta_create_2(t_meta *m)
{
	m->mlx = mlx_init();
	if (!m->mlx)
		return (ERROR_MLX_CONNECTION);
	m->win = mlx_new_window(m->mlx, map_get_size(m).x * IMG_SIZE, \
		(map_get_size(m).y + 1) * IMG_SIZE, GAME_NAME);
	if (!m->win)
		return (ERROR_WINDOW_CREATE);
	m->sprite = sprite_create_and_load(meta_get_mlx(m));
	if (!m->sprite)
		return (ERROR_SPRITE_CREATE);
	return (SUCCESS);
}

static inline int	meta_create_1(t_meta *m, int fd)
{
	int	stt;

	m->map = input_create_map(fd);
	if (!m->map)
		return (ERROR_MAP_CREATE);
	stt = map_validate(m->map);
	if (SUCCESS != stt)
		return (stt);
	m->collect = collect_create();
	if (!m->collect)
		return (ERROR_COLLECT_CREATE);
	collect_set(m, map_count_collect(m));
	stt = player_create(m);
	if (SUCCESS != stt)
		return (stt);
	return (meta_create_2(m));
}

int	meta_init(t_meta *m, int fd)
{
	int		stt;

	stt = meta_create_1(m, fd);
	if (SUCCESS != stt)
	{
		meta_free(m);
		return (stt);
	}
	draw_map(m);
	init_hooks(m);
	return (SUCCESS);
}

void	meta_free(t_meta *m)
{
	if (m->sprite)
		sprite_free(m->sprite, m->mlx);
	if (m->map)
		map_free(m->map);
	if (m->player)
		player_free(m->player);
	if (m->collect)
		collect_free(m->collect);
}

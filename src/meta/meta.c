/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:21:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 18:57:54 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "sprite.h"
#include "window.h"
#include "meta.h"

static t_meta	*meta_create_2(t_meta *m)
{
	m->sprite = sprite_create_and_load(meta_get_mlx(m));
	if (!m->sprite)
	{
		window_free(m->win);
		m->win = NULL;
	}
	return (m);
}

t_meta	*meta_create(int width, int height, char *name)
{
	t_meta	*m;

	m = (t_meta *)malloc(sizeof(t_meta));
	if (!m)
		return (NULL);
	m->mlx = mlx_init();
	if (!m->mlx)
		return (NULL);
	m->win = window_create(m->mlx, width, height, name);
	if (!m->win)
	{
		free(m);
		return (NULL);
	}
	return (meta_create_2(m));
}

void	meta_free(t_meta *m)
{
	sprite_free(m->sprite);
	m->sprite = NULL;
	window_free(m->win);
	m->win = NULL;
	free(m);
}

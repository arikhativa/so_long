/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:21:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 16:54:43 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "window.h"
#include "meta.h"

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
	return (m);
}

void	meta_free(t_meta *m)
{
	window_free(m->win);
	m->win = NULL;
	free(m);
}

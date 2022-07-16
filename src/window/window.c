/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:03 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 16:43:26 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "point.h"
#include "window.h"

t_window	*window_create(void *mlx, int width, int height, char *name)
{
	t_window	*w;

	w = (t_window *)malloc(sizeof(t_window));
	if (!w)
		return (NULL);
	w->size = point_create_set(width, height);
	if (!w->size)
	{
		free(w);
		return (NULL);
	}
	w->ref = mlx_new_window(mlx, width, height, name);
	if (!w->ref)
	{
		point_free(w->size);
		free(w);
		return (NULL);
	}
	return (w);
}

void	window_free(t_window *w, void *mlx)
{
	point_free(w->size);
	w->size = NULL;
	free(w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:03 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 17:50:27 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "point.h"
#include "window.h"

t_window	*window_create(void *mlx, t_point *size)
{
	t_window	*w;

	w = (t_window *)malloc(sizeof(t_window));
	if (!w)
		return (NULL);
	w->size = size;
	w->ref = mlx_new_window(mlx, size->x * IMG_SIZE, size->y * IMG_SIZE, GAME_NAME);
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
	free(w);
}

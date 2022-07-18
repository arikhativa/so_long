/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:25:03 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:27:38 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "point.h"
#include "libft.h"
#include "window.h"

t_window	*window_create(void *mlx, t_point size)
{
	t_window	*w;

	w = (t_window *)ft_calloc(1, sizeof(t_window));
	if (!w)
		return (NULL);
	w->size = point_copy(size);
	w->ref = mlx_new_window(mlx, size.x * IMG_SIZE, (size.y + 1) * IMG_SIZE, \
		GAME_NAME);
	if (!w->ref)
	{
		window_free(w, mlx);
		return (NULL);
	}
	return (w);
}

void	window_free(t_window *w, void *mlx)
{
	free(w);
}

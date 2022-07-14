/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 18:58:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "define.h"
#include "point.h"
#include "mlx.h"
#include "image.h"
#include "sprite.h"
#include "meta.h"

int main(int ac, char **av)
{
	t_meta	*m;
	t_point	p;

	m = meta_create(WIDTH, HEIGHT, NAME);
	if (!m)
		return (ERROR);
	point_set(&p, 0, 0);
	image_put(m->sprite->img_map[0], m, &p);

	point_set(&p, 64, 0);
	image_put(m->sprite->img_map[1], m, &p);

	mlx_loop(meta_get_mlx(m));
	
	return (SUCCESS);
}


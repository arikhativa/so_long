/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 17:48:05 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "define.h"
#include "point.h"
#include "mlx.h"
#include "image.h"
#include "meta.h"

int main(int ac, char **av)
{
	t_meta	*m;
	t_image	*img;
	t_point	p;

	m = meta_create(WIDTH, HEIGHT, NAME);
	if (!m)
		return (ERROR);
	img = image_create();
	if (ERROR == image_load(img, m, "block.xpm"))
		return (ERROR);
	point_set(&p, 0, 0);
	image_put(img, m, &p);

	if (ERROR == image_load(img, m, "wall.xpm"))
		return (ERROR);
	point_set(&p, 64, 0);
	image_put(img, m, &p);

	mlx_loop(meta_get_mlx(m));
	
	return (SUCCESS);
}


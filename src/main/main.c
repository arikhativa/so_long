/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 16:50:00 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "define.h"
#include "image.h"
#include "meta.h"

int main(int ac, char **av)
{
	t_meta	*m;
	t_image	*img;

	m = meta_create(WIDTH, HEIGHT, NAME);
	if (!m)
		return (ERROR);
	img = image_create();
	if (ERROR == image_load(img, m, "./img/block.xpm"))
		return (ERROR);
	image_put(img, m);
	mlx_loop(meta_get_mlx(m));
	
	return (SUCCESS);
}


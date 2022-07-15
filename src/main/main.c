/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 13:15:26 by yrabby           ###   ########.fr       */
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
#include "input.h"

int main(int ac, char **av)
{
	t_meta	*m;
	t_point	p;
	int	fd;
	int	stt;

	if (2 != ac)
		return (ERROR);
	m = meta_create(WIDTH, HEIGHT, NAME);
	if (!m)
		return (ERROR);
	fd = input_open(av[1]);
	if (FD_ERROR == fd)
	{
		perror("fd issue: ");
		return (ERROR);
	}
	stt = input_get_size(fd, &p);
	printf("stt: %d\n", stt);
	printf("x: %d\n", p.x);
	printf("y: %d\n", p.y);
	return (SUCCESS);
}


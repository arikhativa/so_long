/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 17:56:16 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "define.h"
#include "point.h"
#include "mlx.h"
#include "image.h"
#include "sprite.h"
#include "meta.h"
#include "tab.h"
#include "input.h"

int main(int ac, char **av)
{
	t_meta	*m;
	t_point	p;
	int	fd;
	int	stt;

	if (2 != ac)
		return (ERROR);
	fd = input_open(av[1]);
	if (FD_ERROR == fd)
	{
		perror("fd issue: ");
		return (ERROR);
	}
	m = meta_create(WIDTH, HEIGHT, NAME, fd);
	if (m)
	{
		tab_print(m->map->tab);
		printf("map size x: %d\n", m->map->size->x);
		printf("map size y: %d\n", m->map->size->y);
		meta_free(m);
	}
	close(fd);
	return (SUCCESS);
}


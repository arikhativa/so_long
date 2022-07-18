/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:08:53 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "define.h"
#include "point.h"
#include "mlx.h"
#include "image.h"
#include "sprite.h"
#include "meta.h"
#include "tab.h"
#include "input.h"
#include "hook.h"
#include "error.h"
#include "draw.h"
#include "map.h"

int main(int ac, char **av)
{
	t_meta	m;
	int	fd;
	int	stt;

	if (2 != ac)
	{
		error_print(ERROR_ARG);
		return (ERROR);
	}
	fd = input_open(av[1]);
	if (ERROR == fd)
	{
		error_print(ERROR_FD);
		return (ERROR);
	}
	stt = meta_init(&m, fd);
	close(fd);
	if (SUCCESS != stt)
	{
		error_print(stt);
		system("leaks so_long");
		return (ERROR);
	}
	draw_map(&m);
	init_hooks(&m);
	mlx_loop(m.mlx);
	meta_free(&m);
	system("leaks so_long");
	return (SUCCESS);
}

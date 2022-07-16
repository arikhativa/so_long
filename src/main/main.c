/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 12:09:14 by yrabby           ###   ########.fr       */
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
#include "map.h"


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
		stt = map_validate(m->map);
		if (SUCCESS != stt)
		{
			map_error_to_str(stt);
			meta_free(m);
			close(fd);
			return (INVALID_MAP);
		}
		init_hooks(m);
		mlx_loop(m->mlx);
	}
	meta_free(m);
	close(fd);
	// system("leaks so_long");
	return (SUCCESS);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/23 16:12:55 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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

int	main(int ac, char **av)
{
	t_meta	m;
	int		fd;
	int		stt;

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
		return (ERROR);
	}
	mlx_loop(meta_get_mlx(&m));
	meta_free(&m);
	return (SUCCESS);
}

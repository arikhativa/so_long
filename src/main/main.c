/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 12:30:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "define.h"
#include "mlx.h"
#include "meta.h"
#include "error.h"

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

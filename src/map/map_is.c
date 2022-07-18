/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:25:59 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 18:59:04 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "map.h"

int	map_is_wall(t_meta *m, t_point p)
{
	return (WALL_CHAR == map_get_char(m, p));
}

int	map_is_exit(t_meta *m, t_point p)
{
	return (EXIT_CHAR == map_get_char(m, p));
}

int	map_is_collect(t_meta *m, t_point p)
{
	return (COLLECT_CHAR == map_get_char(m, p));
}

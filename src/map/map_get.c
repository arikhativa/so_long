/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:40:21 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 10:30:22 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"
#include "object.h"

t_point	*map_get_size(t_meta *m)
{
	return (m->map->size);
}

char	map_get_char(t_meta *m, t_point *pos)
{
	return (tab_get_char(m->map->tab, pos));
}

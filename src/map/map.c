/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:47:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 12:23:50 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "point.h"
#include "libft.h"
#include "object.h"
#include "tab.h"

t_map	*map_create(t_point size, char **tab)
{
	t_map	*m;

	m = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!m)
		return (NULL);
	m->size = point_copy(size);
	m->tab = tab;
	return (m);
}

void	map_free(t_map *m)
{
	tab_free(m->tab);
	m->tab = NULL;
	free(m);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:41:38 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:55:17 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "lib42.h"
#include "point.h"
#include "object.h"
#include "map.h"
#include "tab.h"
#include "define.h"
#include "input.h"

int	input_open(const char *file_path)
{
	return (open(file_path, O_RDONLY));
}

static t_map	*input_create_map2(char **src_tab, int tab_size)
{
	char	**dest_tab;
	t_map	*m;

	dest_tab = (char **)ft_calloc(tab_size, sizeof(char *));
	if (!dest_tab)
		return (NULL);
	tab_copy(dest_tab, src_tab);
	m = map_create(point_set(MAP_INVALID_X, tab_size - 1), dest_tab);
	if (!m)
	{
		free(dest_tab);
		return (NULL);
	}
	map_clean_player(m);
	return (m);
}

t_map	*input_create_map(int fd)
{
	int		i;
	char	*tab[BER_MAX_LINE];
	char	*line;
	t_map	*m;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	tab[0] = line;
	line = get_next_line(fd);
	i = 1;
	while (line)
	{
		tab[i] = line;
		line = get_next_line(fd);
		++i;
	}
	tab[i] = NULL;
	m = input_create_map2(tab, i + 1);
	if (!m)
	{
		tab_free_lines(tab);
		return (NULL);
	}
	return (m);
}

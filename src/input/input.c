/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:41:38 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 13:19:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "point.h"
#include "object.h"
#include "define.h"
#include "input.h"
#include "get_next_line.h"

int	input_open(const char *file_path)
{
	return (open(file_path, O_WRONLY));
}

static inline int	is_height_valid(int	height)
{
	return (MIN_HEIGHT_LEN > height);
}

int	input_get_size(int fd, t_point *size)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (EMPTY_FILE);
	point_set(size, get_line_size(line), 1);
	if (!is_first_line_size_valid(size->x))
		return (INVALID_MAP);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (!is_mid_line_size_valid(line, size->x))
			return (INVALID_MAP);
		++size->y;
		free(line);
		line = get_next_line(fd);
	}
	if (!is_height_valid(size->y))
		return (INVALID_MAP);
	return (SUCCESS);
}

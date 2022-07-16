/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:48:38 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 10:03:51 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "object.h"

t_map	*map_create(t_point *size, char **tab);
void	map_free(t_map *m);

int	map_validate(t_map *m);

// line.c
int	get_line_size(char *line);
int	is_first_line_size_valid(int len);
int	is_mid_line_size_valid(char *line, int first_line_len);

#endif

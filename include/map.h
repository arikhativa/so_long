/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:48:38 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 18:04:30 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "object.h"

t_map	*map_create(t_point *size, char **tab);
void	map_free(t_map *m);

int	map_validate(t_map *m);

// char_validate
int	map_validate_special_char(t_map *m);

// line.c
int	get_line_size(char *line);
int	is_first_line_size_valid(int len);
int	is_mid_line_size_valid(char *line, int first_line_len);
int	is_topbot_line_chars_valid(const char *line, int size);
int	is_mid_line_chars_valid(const char *line, int size);

void	map_error_to_str(int err);
t_point	*map_get_size(t_meta *m);
char	map_get_char(t_meta *m, t_point *pos);

#endif

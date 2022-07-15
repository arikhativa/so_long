/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:23:55 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 13:19:29 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

int	get_line_size(char *line);
int	is_first_line_size_valid(int len);
int	is_mid_line_size_valid(char *line, int first_line_len);

int	input_get_size(int fd, t_point *size);
int	input_open(const char *file_path);


#endif

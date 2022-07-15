/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:20:59 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 13:19:22 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"

int	get_line_size(char *line)
{
	int	i;

	i = 0;
	while (NEW_LINE != line[i])
		++i;
	return (i);
}

int	is_first_line_size_valid(int len)
{
	return (MIN_WIDTH_LEN > len);
}

int	is_mid_line_size_valid(char *line, int first_line_len)
{
	int	new_len;

	new_len = get_line_size(line);
	if (new_len != first_line_len)
		return (FALSE);
	return (TRUE);
}

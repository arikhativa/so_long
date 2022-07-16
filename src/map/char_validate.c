/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:57:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 11:16:49 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "object.h"
#include "tab.h"

static int	map_is_player_valid(t_map *m)
{
	int	count;

	count = tab_count_char(m->tab, PLAYER_CHAR);
	return (MIN_PLAYER <= count);
}

static int	map_is_collect_valid(t_map *m)
{
	int	count;

	count = tab_count_char(m->tab, COLLECT_CHAR);
	return (MIN_COLLECT <= count);
}

static int	map_is_exit_valid(t_map *m)
{
	int	count;

	count = tab_count_char(m->tab, EXIT_CHAR);
	return (MIN_EXIT <= count);
}

int	map_validate_special_char(t_map *m)
{
	if (!map_is_player_valid(m))
		return (BAD_PLAYER);
	if (!map_is_collect_valid(m))
		return (BAD_COLLECT);
	if (!map_is_exit_valid(m))
		return (BAD_EXIT);
	return (SUCCESS);
}

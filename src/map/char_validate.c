/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <files.associations>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:57:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 13:07:43 by yrabby           ###   ########.fr       */
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
		return (ERROR_PLAYER);
	if (!map_is_collect_valid(m))
		return (ERROR_COLLECT);
	if (!map_is_exit_valid(m))
		return (ERROR_EXIT);
	return (SUCCESS);
}

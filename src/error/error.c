/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:30:49 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 19:01:47 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "ft_printf.h"

static void	error_print_msg(char *err_msg, int error_code)
{
	ft_printf("Error\n\tERROR CODE: %d\n\t%s\n", error_code, err_msg);
}

static void	error_print1(int err)
{
	if (ERROR_CHAR_TOP == err)
		error_print_msg("Map error: Invalid char at first line", err);
	else if (ERROR_CHAR_MID == err)
		error_print_msg("Map error: Invalid char at middle of map", err);
	else if (ERROR_CHAR_BOTTOM == err)
		error_print_msg("Map error: Invalid char at bottom line", err);
	else if (ERROR_SIZE_TOP == err)
		error_print_msg("Map error: not wide enough", err);
	else if (ERROR_SIZE_MID == err)
		error_print_msg("Map error: lines are not the same size", err);
	else if (ERROR_SIZE_BOTTOM == err)
		error_print_msg("Map error: issue with bottom line size", err);
	else if (ERROR_HEIGHT == err)
		error_print_msg("Map error: not high enough", err);
	else if (ERROR_PLAYER == err)
		error_print_msg("Map error: missing player", err);
	else if (ERROR_COLLECT == err)
		error_print_msg("Map error: missing collectable", err);
	else if (ERROR_EXIT == err)
		error_print_msg("Map error: missing exitt", err);
}

void	error_print2(int err)
{
	if (ERROR_MLX_CONNECTION == err)
		error_print_msg("MLX error: failed to init mlx", err);
	else if (ERROR_ARG == err)
		error_print_msg("Argument error: expect exactly one argument", err);
	else if (ERROR_FD == err)
		error_print_msg("fd error: failed to open file", err);
	else if (ERROR_MAP_CREATE == err)
		error_print_msg("Allocation error: failed create map", err);
	else if (ERROR_SPRITE_CREATE == err)
		error_print_msg("Allocation error: failed create sprites", err);
	else if (ERROR_WINDOW_CREATE == err)
		error_print_msg("Allocation error: failed create window", err);
	else if (ERROR_PLAYER_CREATE == err)
		error_print_msg("Allocation error: failed create player", err);
}

void	error_print(int error_code)
{
	error_print1(error_code);
	error_print2(error_code);
}

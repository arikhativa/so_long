/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <files.associations>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:30:49 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 13:16:19 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "ft_printf.h"

void	error_print_msg(char *err_msg, int error_code)
{
	ft_printf("Error\n\tERROR CODE: %d\n\t%s\n", error_code, err_msg);
}

void	error_map(int err)
{
	if (ERROR_CHAR_TOP == err)
		error_print("Map error: Invalid char at first line", err);
	else if (ERROR_CHAR_MID == err)
		error_print("ERROR_CHAR_MID", err);
	else if (ERROR_CHAR_BOTTOM == err)
		error_print("ERROR_CHAR_BOTTOM", err);
	else if (ERROR_SIZE_TOP == err)
		error_print("ERROR_SIZE_TOP", err);
	else if (ERROR_SIZE_MID == err)
		error_print("ERROR_SIZE_MID", err);
	else if (ERROR_SIZE_BOTTOM == err)
		error_print("ERROR_SIZE_BOTTOM", err);
	else if (ERROR_HEIGHT == err)
		error_print("ERROR_HEIGHT", err);
	else if (ERROR_PLAYER == err)
		error_print("ERROR_PLAYER", err);
	else if (ERROR_COLLECT == err)
		error_print("ERROR_COLLECT", err);
	else if (ERROR_EXIT == err)
		error_print("ERROR_EXIT", err);
}

void error_print2(int err)
{
	if (ERROR_ALOCATION == err)
		error_print("Allocation error: falied to allocate memory", err);
	else if (ERROR_MLX_CONACTION == err)
		error_print("MLX error: failed to init mlx", err);
	else if (ERROR_ARG == err)
		error_print("Argument error: program expect exectly one argument", err);
}

void	error_print(int error_code)
{
	error_print1(error_code);
	error_print2(error_code);
}

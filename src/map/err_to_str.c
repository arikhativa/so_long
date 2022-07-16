/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:18:56 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 11:30:02 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "ft_printf.h"

static void	print_err(char *errstr)
{
	ft_printf("Error: map is invalid. ERROR CODE: %s\n", errstr);
}

void	map_error_to_str(int err)
{
	if (BAD_CHAR_TOP == err)
		print_err("BAD_CHAR_TOP");
	else if (BAD_CHAR_MID == err)
		print_err("BAD_CHAR_MID");
	else if (BAD_CHAR_BOTTOM == err)
		print_err("BAD_CHAR_BOTTOM");
	else if (BAD_SIZE_TOP == err)
		print_err("BAD_SIZE_TOP");
	else if (BAD_SIZE_MID == err)
		print_err("BAD_SIZE_MID");
	else if (BAD_SIZE_BOTTOM == err)
		print_err("BAD_SIZE_BOTTOM");
	else if (BAD_HEIGHT == err)
		print_err("BAD_HEIGHT");
	else if (BAD_PLAYER == err)
		print_err("BAD_PLAYER");
	else if (BAD_COLLECT == err)
		print_err("BAD_COLLECT");
	else if (BAD_EXIT == err)
		print_err("BAD_EXIT");
	else
		print_err("unkown error-code");
}

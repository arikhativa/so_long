/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:31:32 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 12:23:50 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "player.h"
#include "object.h"

void	print_move_counter(t_meta *m)
{
	ft_printf("Current Move: %d\n", player_get_move_counter(m));
}

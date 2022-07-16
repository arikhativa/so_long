/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:15:29 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 17:38:31 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "define.h"
#include "object.h"

int	handler_close(int keycode, t_meta *m)
{
	printf("close\n");
	// TODO does not work for some reason
	// meta_free(m);
	// system("leaks so_long");
	exit(0);
}

int	handler_key_press(int keycode, t_meta *m)
{
	if (ESC == keycode)
		handler_close(keycode, m);
	printf("keyyy\n");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:45:09 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 16:57:43 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "mlx.h"
#include "meta.h"

#include <stddef.h>


int	handler_key_press(int keycode, void *param)
{
	printf("keyyy\n");
	return (1);
}

int	handler_close(int keycode, t_meta *m)
{
	printf("close\n");
	system("leaks so_long");
	exit(0);
}

void	init_hooks(t_meta *m)
{
	mlx_hook(m->win->ref, KEY_PRESS, 0, handler_key_press, NULL);
	mlx_hook(m->win->ref, DESTORY_WINDOW, 0, handler_close, m);
}

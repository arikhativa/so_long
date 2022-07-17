/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:45:09 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 15:11:21 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "mlx.h"
#include "meta.h"
#include "handler.h"

#include <stddef.h>


void	init_hooks(t_meta *m)
{
	mlx_hook(m->win->ref, KEY_PRESS, 0, handler_key_press, m);
	mlx_hook(m->win->ref, DESTROY_WINDOW, 0, handler_close, m);
}

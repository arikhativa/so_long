/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:08:09 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 12:09:38 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

#include "object.h"

int	handler_key_press(int keycode, void *param);
int	handler_close(int keycode, void *param);
void	init_hooks(t_meta *m);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:16:46 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 18:56:20 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

# include "object.h"

int	handler_key_press(int keycode, t_meta *m);
int	handler_close(int keycode, t_meta *m);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:20:31 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 19:30:43 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "object.h"

t_window	*window_create(void *mlx, int width, int height, char *name);
void		window_free(t_window *w, void *mlx);

void		*window_get_win(t_window *w);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:20:31 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 16:43:30 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "point.h"

typedef struct s_window
{
	void		*ref;
	t_point		*size;
}				t_window;

t_window	*window_create(void *mlx, int width, int height, char *name);
void		window_free(t_window *w);

void		*window_get_win(t_window *w);

#endif

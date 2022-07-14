/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:19:23 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 15:41:28 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_H
# define META_H

# include "window.h"

typedef struct	s_meta {
	void		*mlx;
	t_window	*win;
	// t_image		sprite;
	// t_vector	sprite_position;
}				t_meta;

t_meta	*meta_create(int width, int height, char *name);
void	meta_free(t_meta *m);

#endif

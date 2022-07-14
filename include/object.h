/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:47:20 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 18:55:03 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "define.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image
{
	void		*ref;
	t_point		*size;
	char		*pixel;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_sprite
{
	t_image	*img_map[NUM_OF_SPRITES];
}	t_sprite;

typedef struct s_window
{
	void		*ref;
	t_point		*size;
}				t_window;

typedef struct s_meta
{
	void		*mlx;
	t_window	*win;
	t_sprite	*sprite;
}				t_meta;

#endif

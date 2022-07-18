/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:47:20 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:24:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "define.h"

typedef struct s_collect
{
	int	num_of_collect;
}	t_collect;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	int	is_enable;
	int	move_counter;
	t_point	pos;
}	t_player;

typedef struct s_map
{
	char	**tab;
	t_point	size;
}	t_map;

typedef struct s_image
{
	void		*ref;
	t_point		size;
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
	// size is in the control of map
	t_point		size;
}				t_window;

typedef struct s_meta
{
	void		*mlx;
	t_window	*win;
	t_sprite	*sprite;
	t_map		*map;
	t_player	*player;
	t_collect	*collect;
}				t_meta;

typedef t_point (*t_point_move)(t_point p);

#endif

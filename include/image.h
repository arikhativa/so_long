/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:47:18 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 15:10:48 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "point.h"

typedef struct	s_image {
	void		*ref;
	t_point		*size;
	char		*pixel;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

t_image	*image_create(void);
int		image_load(t_image *img, void *mlx, char *path);
void    image_free(t_image *img);

#endif

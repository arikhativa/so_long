/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:47:18 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 19:25:53 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "object.h"

t_image	*image_create(void);
int		image_load(t_image *img, void *mlx, char *path);
void	image_free(t_image *img, void *mlx);
void	image_put(t_image *img, t_meta *m, t_point *p);
t_image	*image_create_and_load(void	*mlx, char *name);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:47:18 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:17:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "object.h"

t_image	*image_create(void);
int		image_load(t_image *img, void *mlx, char *path);
void	image_free(t_image *img, void *mlx);
void	image_put(t_image *img, t_meta *m, t_point p);

void	*get_image(t_meta *m, int img_index);

#endif

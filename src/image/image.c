/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:52:30 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 16:45:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "define.h"
#include "point.h"
#include "image.h"
#include "meta.h"
#include "mlx.h"

t_image	*image_create(void)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->size = point_create();
	if (!img->size)
	{
		free(img);
		return (NULL);
	}
	return (img);
}

void	image_free(t_image *img)
{
	point_free(img->size);
	img->size = NULL;
	free(img);
}

int	image_load(t_image *img, t_meta *m, char *path)
{
	img->ref = mlx_xpm_file_to_image(meta_get_mlx(m), path, &(img->size->x), \
		&(img->size->y));
	if (!img->ref)
		return (ERROR);
	img->pixel = mlx_get_data_addr(img->ref, img->bits_per_pixel, \
		&(img->line_size), &(img->endian));
	if (!img->pixel)
		return (ERROR);
	return (SUCCESS);
}

void	image_put(t_image *img, t_meta *m)
{
	mlx_put_image_to_window(
		meta_get_mlx(m), \
		meta_get_win(m), \
		img->ref, \
		img->size->x, \
		img->size->y \
	);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:52:30 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 15:15:37 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "define.h"
#include "point.h"
#include "image.h"
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

int	image_load(t_image *img, void *mlx, char *path)
{
	img->ref = mlx_xpm_file_to_image(mlx, path, &(img->size->x), \
		&(img->size->y));
	if (!img->ref)
		return (ERROR);
	img->pixel = mlx_get_data_addr(img->ref, img->bits_per_pixel, \
		&(img->line_size), &(img->endian));
	if (!img->pixel)
		return (ERROR);
	return (SUCCESS);
}

void	image_free(t_image *img)
{
	point_free(img->size);
	img->size = NULL;
	free(img);
}

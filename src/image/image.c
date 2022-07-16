/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:52:30 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 13:21:06 by yrabby           ###   ########.fr       */
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

void	image_free(t_image *img, void *mlx)
{
	point_free(img->size);
	img->size = NULL;
	// mlx_destroy_image(mlx, img->ref);
	free(img);
}

// TODO 
static void	init_path(char path[MAX_PATH], char *file_name)
{
	char	*xpm_path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	xpm_path = XPM_PATH;
	while (xpm_path[i])
	{
		path[i] = xpm_path[i];
		++i;
	}
	while (file_name[j])
	{
		path[j + i] = file_name[j];
		++j;
	}
	path[j + i] = '\0';
}

int	image_load(t_image *img, void *mlx, char *file_name)
{
	char	path[MAX_PATH];

	init_path(path, file_name);
	img->ref = mlx_xpm_file_to_image(mlx, path, &(img->size->x), \
		&(img->size->y));
	if (!img->ref)
		return (ERROR);
	img->pixel = mlx_get_data_addr(img->ref, &(img->bits_per_pixel), \
		&(img->line_size), &(img->endian));
	if (!img->pixel)
		return (ERROR);
	return (SUCCESS);
}

void	image_put(t_image *img, t_meta *m, t_point *p)
{
	mlx_put_image_to_window(
		meta_get_mlx(m), \
		meta_get_win(m), \
		img->ref, \
		p->x, \
		p->y \
	);
}

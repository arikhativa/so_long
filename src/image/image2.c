/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:14:36 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 11:18:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "define.h"
#include "image.h"

t_image	*image_create_and_load(void	*mlx, char *name)
{
	t_image	*img;

	img = image_create();
	if (!img)
		return (NULL);
	if (ERROR == image_load(img, mlx, name))
	{
		free(img);
		return (NULL);
	}
	return (img);
}

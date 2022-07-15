/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:31:33 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 19:28:55 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "define.h"
#include "image.h"
#include "sprite.h"
#include "meta.h"

static int	sprite_check_create(t_sprite *s)
{
	int	i;

	i = 0;
	while (NUM_OF_SPRITES > i)
	{
		if (!s->img_map[i])
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

t_sprite *sprite_create(void *mlx)
{
	int		i;
	t_sprite *s;

	s = (t_sprite *)malloc(sizeof(t_sprite));
	if (!s)
		return (NULL);
	i = 0;
	while (NUM_OF_SPRITES > i)
	{
		s->img_map[i] = image_create();
		++i;
	}
	if (ERROR == sprite_check_create(s))
	{
		sprite_free(s, mlx);
		return (NULL);
	}
	return (s);
}

int sprite_load(t_sprite *s, void *mlx)
{
	int	stt;

	stt = SUCCESS;
	stt += image_load(s->img_map[WALL_I], mlx, WALL_STR);
	stt += image_load(s->img_map[BLOCK_I], mlx, BLOCK_STR);
	if (SUCCESS != stt)
		return (ERROR);
	return (SUCCESS);
}

t_sprite *sprite_create_and_load(void *mlx)
{
	t_sprite *s;

	s = sprite_create(mlx);
	if (!s)
		return (NULL);
	if (ERROR == sprite_load(s, mlx))
	{
		sprite_free(s, mlx);
		return (NULL);
	}
	return (s);
}

void	sprite_free(t_sprite *s, void *mlx)
{
	int	i;

	i = 0;
	while (NUM_OF_SPRITES > i)
	{
		if (s->img_map[i])
		{
			image_free(s->img_map[i], mlx);
			s->img_map[i] = NULL;
		}
		++i;
	}
	free(s);
}

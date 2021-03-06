/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:15:57 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 19:16:05 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "object.h"

t_sprite	*sprite_create_and_load(void *mlx);
t_sprite	*sprite_create(void *mlx);
int			sprite_load(t_sprite *s, void *mlx);
void		sprite_free(t_sprite *s, void *mlx);

#endif

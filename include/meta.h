/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:19:23 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 18:49:27 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_H
# define META_H

# include "object.h"

t_meta	*meta_create(int width, int height, char *name);
void	meta_free(t_meta *m);

void	*meta_get_mlx(t_meta *m);
void	*meta_get_win(t_meta *m);

#endif

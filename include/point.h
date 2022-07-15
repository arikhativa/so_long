/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:50:41 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 11:56:13 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "object.h"

t_point	*point_create(void);
t_point	*point_create_set(int x, int y);
t_point	*point_create_copy(t_point *p);
void	point_free(t_point *p);
void	point_set(t_point *p, int x, int y);

#endif

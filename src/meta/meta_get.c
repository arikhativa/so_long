/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:35:24 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 16:37:40 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "meta.h"

inline void	*meta_get_mlx(t_meta *m)
{
    return (m->mlx);
}

inline void	*meta_get_win(t_meta *m)
{
    return (window_get_win(m->win));
}
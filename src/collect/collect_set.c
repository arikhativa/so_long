/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:36:56 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:50:58 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

void	collect_decries(t_meta *m)
{
	--m->collect->num_of_collect;
}

void	collect_set(t_meta *m, int collect)
{
	m->collect->num_of_collect = collect;
}

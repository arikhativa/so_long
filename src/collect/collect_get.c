/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:38:06 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:39:29 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int	collect_is_done(t_meta *m)
{
	printf("col: %d\n", m->collect->num_of_collect);
	return (0 == m->collect->num_of_collect);
}

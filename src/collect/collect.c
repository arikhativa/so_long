/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:32:43 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:15:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "lib42.h"
#include "object.h"

t_collect	*collect_create(void)
{
	t_collect	*c;

	c = ft_calloc(1, sizeof(t_collect));
	if (!c)
		return (NULL);
	return (c);
}

void	collect_free(t_collect *c)
{
	if (c)
	{
		c->num_of_collect = 0;
		free(c);
	}
}

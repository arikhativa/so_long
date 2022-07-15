/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:59:33 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 13:17:32 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "object.h"

void	tab_free(char **tab)
{
	int	i;

	i = 0;
	while (NULL != tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		++i;
	}
	free(tab);
}

char	**tab_create(t_point *size)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char *) * (size->y + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size->y)
	{
		tab[i] = (char *)malloc(sizeof(char) * (size->x + 1));
		if (!(tab[i]))
		{
			tab_free(tab);
			return (NULL);
		}
		++i;
	}
	tab[i] = NULL;
}

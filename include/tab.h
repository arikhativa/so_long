/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:04:08 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 18:40:15 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

# include "object.h"

void	tab_copy(char **d, char **s);
void	tab_free_lines(char **tab);
void	tab_free(char **tab);
int		tab_count_char(char **tab, char c);
char	tab_get_char(char **tab, t_point p);
void	tab_set(char **tab, t_point p, char c);

#endif

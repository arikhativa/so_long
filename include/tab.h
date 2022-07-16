/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:04:08 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 11:01:33 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

// TODO remove..
void	tab_print(char **tab);
void	tab_copy(char **d, char **s);
void	tab_free_lines(char **tab);
void	tab_free(char **tab);
int		tab_count_char(char **tab, char c);

#endif

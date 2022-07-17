/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:38:53 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 16:08:50 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECT_H
# define COLLECT_H

# include "object.h"

t_collect	*collect_create(void);
void		collect_free(t_collect *c);
void		collect_decries(t_meta *m);
int			collect_is_done(t_meta *m);
void		collect_set(t_meta *m, int collect);

#endif

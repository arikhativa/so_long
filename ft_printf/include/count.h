/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:00:11 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 12:29:34 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_H
# define COUNT_H

# include <stddef.h>

size_t	count_digit_by_base(long n, long base);
size_t	count_digit_by_base_unsigned(size_t n, size_t base);

#endif

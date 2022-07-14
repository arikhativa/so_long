/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:55:04 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 13:40:02 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "mlx.h"
#include "define.h"

void    circle_draw(int r, int x, int y, int bits_per_pixel, int size_line, char *data_addr, char color);


void    add_line(int x, int y, int bits_per_pixel, int size_line, char *data_addr, char color)
{
    int i;
    while (90 > x)
    {
        i = (x * bits_per_pixel / 8) + (y * size_line);
	    data_addr[i] = 0;
	    data_addr[++i] = 0;
	    data_addr[++i] = 127;
	    data_addr[++i] = 0;
        ++x;
    }
}


int main(int ac, char **av)
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *data_addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
    int i = 0;
 

    mlx = mlx_init();

    win = mlx_new_window(mlx, 100, 100, "yesssss");
    img = mlx_new_image(mlx, 101, 100);

    data_addr = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
   int x = 50;
    int y = 50;
    int color = 5;

    circle_draw(20, x, y, bits_per_pixel, size_line, data_addr, color);

    mlx_put_image_to_window(mlx, win, img, 0, 0);
    
    mlx_loop(mlx);
// int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
    
    return (SUCCESS);
}


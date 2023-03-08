/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:31 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/08 16:43:19 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key)
{
	if (key == ESC_KEY)
	{
		exit_();
		return (0);
	}
	if (key == ONE)
	{
		data()->move_x = 0.0;
		data()->move_y = 0.0;
		data()->zoomfactor = 1.0;
		data()->set = MANDELBROT;
		selector();
	}
	if (key == TWO)
	{
		data()->move_x = 0.0;
		data()->move_y = 0.0;
		data()->zoomfactor = 1.0;
		data()->j_cr = -0.7;
    	data()->j_ci = 0.27015;
		data()->set = JULIA;
		selector();
	}
	if (key == KEY_I || key == MOUSE_WHEEL_UP)
	{
		data()->zoomfactor += 1.0;
		selector();
	}
	if (key == KEY_O || key == MOUSE_WHEEL_DOWN)
	{
		if (data()->zoomfactor == 1.0)
		{
			printf("PROTECTION\n");
			return (0);
		}
		data()->zoomfactor -= 1.0;
		selector();
	}
	if (key == LEFT)
	{
		data()->move_x -= 0.035;
		selector();
	}
	if (key == RIGHT)
	{
		data()->move_x += 0.035;
		selector();
	}
	if (key == UP)
	{
		data()->move_y -= 0.035;
		selector();
	}
	if (key == DOWN)
	{
		data()->move_y += 0.035;
		selector();
	}
	if (key == MOUSE_BTN)
	{
		if (data()->set == JULIA)
		{
			int x, y;
			double x2, y2;

			printf("%f , %f \n", data()->j_cr, data()->j_ci);
			
			mlx_mouse_get_pos(data()->mlx, data()->window, &x, &y);

			x2 = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
			y2 = (y - HEIGHT / 2) / (0.5 * HEIGHT);
			
			data()->j_ci = y2;
			data()->j_cr = x2;

			printf("%f , %f \n", data()->j_cr, data()->j_ci);

			selector();
		}
	}
/*  	else
		printf("%i\n", key); */
	return (0);
}

	/* if (key == KEY_D)
	{
		mlx_destroy_image(data()->mlx, img()->img);
		data()->buf = NULL;
		img()->img = mlx_new_image(data()->mlx, WIDTH, HEIGHT);
		data()->buf = mlx_get_data_addr(img()->img, &img()->bits_per_pixel, &img()->line_length, &img()->endian);
		mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
	} */
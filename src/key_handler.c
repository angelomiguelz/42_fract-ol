/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:31 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/09 17:13:09 by parallels        ###   ########.fr       */
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
		return (0);
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
		return (0);
	}
	if (key == KEY_I || key == MOUSE_WHEEL_UP)
	{
		data()->zoomfactor += 0.5;
		selector();
		return (0);
	}
	if (key == KEY_O || key == MOUSE_WHEEL_DOWN)
	{
		if (data()->zoomfactor == 1.0)
			return (0);
		data()->zoomfactor -= 0.5;
		selector();
		return (0);
	}
	if (key == LEFT)
	{
		data()->move_x -= 0.035;
		selector();
		return (0);
	}
	if (key == RIGHT)
	{
		data()->move_x += 0.035;
		selector();
		return (0);
	}
	if (key == UP)
	{
		data()->move_y -= 0.035;
		selector();
		return (0);
	}
	if (key == DOWN)
	{
		data()->move_y += 0.035;
		selector();
		return (0);
	}
	if (key == MOUSE_BTN)
	{
		if (data()->set == JULIA)
		{
			int x, y;
			double x2, y2;			
			mlx_mouse_get_pos(data()->mlx, data()->window, &x, &y);

			x2 = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
			y2 = (y - HEIGHT / 2) / (0.5 * HEIGHT);

			data()->j_ci = y2;
			data()->j_cr = x2;
			selector();
		}
		return (0);
	}
	if (key == NINE)
	{
		img()->color = 1;
		selector();
	}
	if (key == EIGHT)
	{
		img()->color = 2;
		selector();
	}
	if (key == SEVEN)
	{
		img()->color = 3;
		selector();
	}
	else
		printf("%i\n", key);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:31 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/06 14:20:55 by parallels        ###   ########.fr       */
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
		data()->set = MANDELBROT;
		selector();
	}
	if (key == TWO)
	{
		data()->set = JULIA;
		selector();
	}
	if (key == KEY_W)
		zoom(data()->zoomfactor += 1);
	if (key == KEY_S)
		zoom(1.0 - (data()->zoomfactor - 1.0));
	if (key == MOUSE_BTN)
		mlx_mouse_get_pos(data()->mlx, data()->window, &data()->mouse_x, &data()->mouse_y);
/* 	else
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
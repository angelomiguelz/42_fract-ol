/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:32:03 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/13 14:13:44 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*pixel;

	pixel = img()->addr + (y * img()->line_length + x * (img()->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

t_data	*data(void)
{
	static t_data data;
	return (&data);
}

t_img	*img(void)
{
	static t_img img;
	return (&img);
}


void	selector()
{
	if (data()->set == MANDELBROT)
		render_mandelbrot();
	if (data()->set == JULIA)
		render_julia();
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		get_info(av);
		start();
		selector();

		mlx_key_hook(data()->window, key_handler, data());
		mlx_hook(data()->window, EVENT_CLOSE_BTN, 0, exit_, data());
		mlx_mouse_hook(data()->window, key_handler, data());
		mlx_loop(data()->mlx);
	}
	else
		error_help();
	return (0);
}

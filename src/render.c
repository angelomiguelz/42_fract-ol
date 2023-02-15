/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/15 15:09:57 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	calculate_iterations(double pixelr, double pixeli)
{
	int	iterations;

	iterations = mandelbrot(pixelr, pixeli);
	return (iterations);
}

void	render()
{
	int	x;
	int	y;
	double	pixelr;
	double	pixeli;
	int		iterations;

	mlx_clear_window(data()->mlx, data()->window);
	img()->img = mlx_new_image(data()->mlx, WIDTH, HEIGHT);
	img()->addr = mlx_get_data_addr(img()->img, &img()->bits_per_pixel, &img()->line_length, &img()->endian);

	data()->r_max = 2;
	data()->i_max = 1;
	data()->r_min = -2;
	data()->i_min = -1;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixelr = data()->r_min + (double)x * (data()->r_max - data()->r_min) / WIDTH;
			pixeli = data()->i_max + (double)y * (data()->i_min - data()->i_max) / HEIGHT;

			iterations = calculate_iterations(pixelr, pixeli);
			if (iterations > 0)
				printf("iterations: %d\n", iterations);
			my_mlx_pixel_put(x, y, 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
}

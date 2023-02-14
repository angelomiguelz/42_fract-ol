/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/14 11:13:16 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	calculate_iterations(double pixelr, double pixeli, t_data *fractol)
{
	int	iterations;
	(void)fractol;

	iterations = mandelbrot(pixelr, pixeli);
	return (iterations);
}

void	render()
{
	double	x;
	double	y;
	double	pixelr;
	double	pixeli;
	int		iterations;

	mlx_clear_window(data()->mlx, data()->window);
	mlx_new_image(data()->mlx, WIDTH, HEIGHT);

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
			pixelr = data()->r_min + x * (data()->r_max - data()->r_min) / WIDTH;
			pixeli = data()->i_max + y * (data()->i_min - data()->i_max) / HEIGHT;
			iterations = calculate_iterations(pixelr, pixeli, data());
			my_mlx_pixel_put(x, y, 0xFFFFFF);
		}
	}
	printf("Iterations: %i\n", iterations);
	mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
}

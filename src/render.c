/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/26 16:58:35 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_color(int iterations, int x, int y)
{
	if (iterations == MAX_ITERATIONS)
		my_mlx_pixel_put(x, y, 0x000000);
	else
		my_mlx_pixel_put(x, y, 0xFFFFFF);
}

int	get_iterations(double pixelr, double pixeli)
{
	if (data()->set == 1)
		return(mandelbrot(pixelr, pixeli));
	if (data()->set == 2)
		return(julia(pixelr, pixeli));
	return (0);
}

void	render()
{
	int	x;
	int	y;
	double	pixelr;
	double	pixeli;
	int		iterations;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			//pixelr = 3.0 / WIDTH * x - 2;
			//pixeli = -2.0 / HEIGHT * y + 1;

			pixelr = 3.0 / WIDTH * x - 2;
			pixeli = -2.0 / HEIGHT * y + 1;


			iterations = get_iterations(pixelr, pixeli);
			if (iterations == 0)
				printf("HERE\n");

			get_color(iterations, x, y);
		}
	}
	mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
}

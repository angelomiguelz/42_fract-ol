/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/10 13:39:16 by parallels        ###   ########.fr       */
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

//Render for everything to work independetly
//TODO: Calculate nbr of iteractions, set color accordengly, iterate each pixel
void	render(t_data *data)
{
	int	x;
	int	y;
	double	pixelr;
	double	pixeli;
	int		iterations;

	mlx_clear_window(data->mlx, data->window);

	data->r_max = 2;
	data->i_max = 1;
	data->r_min = -2;
	data->i_min = -1;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{ //Check when working if i can put just x double in int
			pixelr = data->r_min + (double)x * (data->r_max - data->r_min) / WIDTH;
			pixeli = data->i_max + (double)y * (data->i_min - data->i_max) / HEIGHT;
			iterations = calculate_iterations(pixelr, pixeli, data);
		}
	}
	//printf("Iterations: %i\n", iterations);
	//mlx_put_image_to_window(data->mlx, data->window, data->image.img, 0, 0);
}

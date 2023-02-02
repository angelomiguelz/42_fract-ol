/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/02 16:12:48 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*Puts default data into the structure for protection and debugging purposes*/
void	default_data(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->f_set = MANDELBROT;
}

/*A clenear and more complete init and window starter with protections*/
void	start_init(t_data *data)
{
	data->mlx = mlx_init();
	/* TODO: Protect if mlx was initialized or not */
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "GABI E GAY");
	/* TODO: Protect if window was initialized or not */
}

static void	set_pixel_color(int x, int y, int color, t_data *f)
{
		f->buf[x * 4 + y * WIDTH * 4] = color;
		f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

static int	calculate_iterations(double pixelr, double pixeli, t_data *fractol)
{
	int	iterations;

	if (fractol->f_set == MANDELBROT)
		iterations = mandelbrot(pixelr, pixeli);
	return (iterations);
}

//Render for everything to work independetly
//TODO: Calculate nbr of iteractions, set color accordengly, iterate each pixel
void	render(t_data *data)
{
	double	x;
	double	y;
	double	pixelr;
	double	pixeli;
	int		iterations;

	mlx_clear_window(data->mlx, data->window);

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixelr = data->r_min + x * (data->r_max - data->r_min) / WIDTH;
			pixeli = data->i_max + y * (data->i_min - data->i_max) / HEIGHT;
			iterations = calculate_iterations(pixelr, pixeli, data);
			set_pixel_color(x, y, data->image.palette[iterations], data);
		}
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image.img, 0, 0);
}

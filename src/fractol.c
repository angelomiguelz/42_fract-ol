/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:32:03 by mzarichn          #+#    #+#             */
/*   Updated: 2023/01/30 18:32:23 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

static void	set_pixel_color(t_data *f, int x, int y, int color)
{
		f->buf[x * 4 + y * WIDTH * 4] = color;
		f->buf[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
		f->buf[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
		f->buf[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}


static int	calculate_fractal(t_data *f, double pr, double pi)
{
	int	nb_iter;

	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	return (nb_iter);
}

static void	render(t_data *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->window);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			set_pixel_color(f, x, y, f->palette[nb_iter]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img, 0, 0);
}


int main(int ac, char **av)
{
	t_data	fractol;

	if (ac < 2)
		help_msg(&fractol);
	(void)av;
	
	default_data(&fractol);
	start_init(&fractol);
		render(&fractol);
	mlx_key_hook(fractol.window, key_handler, &fractol);
	mlx_hook(fractol.window, EVENT_CLOSE_BTN, 0, clean_exit, &fractol);
	mlx_loop(fractol.mlx);
}
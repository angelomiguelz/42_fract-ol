/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/08 16:07:40 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



unsigned int	get_color(int n)
{
	//int	color;

	if (n == MAX_ITERATIONS)
		return(0x000000);
	return (0xFFFFFF);

/* 	if (n > 30)
		color = 256 * n + 16704000;
	else if (n <= 30)
		color = 6.5 * n + 60;
	return (color); */
	
	/* int	color;

	if (iterations < 20)
		color = 5.26 * iterations + 60;
	else if (iterations >= 20 && iterations < 65)
		color = -256 * iterations * 10 + 13167612;
	else if (iterations >= 65)
		color = -256 * iterations + 16777215;
	return (color); */
	/* if (iterations == MAX_ITERATIONS)
		return(0x000000); */
}

void	render_mandelbrot()
{
  //each iteration, it calculates: newz = oldz*oldz + p, where p is the current pixel, and oldz stars at the origin
  double	zr;
  double	zi;
  double	temp;
  double	pixelr;
  double	pixeli;
  int		x;
  int		y;
  int		i;
  
  y = -1;
  while(++y < HEIGHT)
  {
	x = -1;
	while(++x < WIDTH)
	{
		//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
		pixelr = 1.5 * (x - WIDTH / 2) / (0.5 * data()->zoomfactor * WIDTH) + (data()->move_x - 0.5);
		pixeli = (y - HEIGHT / 2) / (0.5 * data()->zoomfactor * HEIGHT) + data()->move_y;
		i = 0;
		zr = 0;
		zi = 0;
		while(i < MAX_ITERATIONS)
		{
			if((zr * zr + zi * zi) > 4)
				break;
			temp = 2 * zr * zi + pixeli;
			zr = zr * zr - zi * zi + pixelr;
			zi = temp;
			i++;
		}
		my_mlx_pixel_put(x, y, get_color(i));
	}
	
  }
  mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
}

void	render_julia()
{
	int		x;
	int		y;
	double	zr;
	double	zi;
	double	temp;
	int		i;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			//convert pixel coord to complex number (Re / Im)
			zr = 1.5 * (x - WIDTH / 2) / (0.5 * data()->zoomfactor * WIDTH) + data()->move_x;
   			zi = (y - HEIGHT / 2) / (0.5 * data()->zoomfactor * HEIGHT) + data()->move_y;

			//calculates the n of iterations until the pos escapes the set
			i = -1;
			while(++i < MAX_ITERATIONS)
			{
				temp = 2 * zr * zi + data()->j_ci;
				zr = zr * zr - zi * zi + data()->j_cr;
				zi = temp;
				//pos outside 2 radius circule
				if((zr * zr + zi * zi) > 4) 
					break;
			}
			my_mlx_pixel_put(x, y, get_color(i));
		}
	}
	mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
}

int	mandelbox(double cr, double ci);

void	render_mandelbox()
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(data()->mlx, data()->window);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = 1.5 * (x - WIDTH / 2) / (0.5 *  WIDTH);
   			pi = (y - HEIGHT / 2) / (0.5  * HEIGHT);
			nb_iter = mandelbox(pr, pi);
			get_color(nb_iter);
		}
	}
	mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
}

double	box_fold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

/* mandelbox:
*	Checks whether a complex number is part of the Mandelbox set or not.
*	Takes as parameters the real and imaginary coordinates of a point,
*	converted previously from a pixel's coordinates.
*	Returns the number of iterations before the number escapes 
*	the Mandelbox set, which can then be used to determine coloring.
*/
int	mandelbox(double cr, double ci)
{
	int		n;
	double	vr;
	double	vi;
	double	mag;

	vr = cr;
	vi = ci;
	mag = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{		
		vr = 1.0 * box_fold(vr);
		vi = 1.0 * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
		vr = vr * 2.0 * ball_fold(0.5, mag) + cr;
		vi = vi * 2.0 * ball_fold(0.5, mag) + ci;
		if (sqrt(mag) > 2)
			break ;
		n++;
	}
	return (n);
}
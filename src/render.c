/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/07 15:01:19 by parallels        ###   ########.fr       */
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
			//color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < MAX_ITERATIONS)));
			my_mlx_pixel_put(x, y, get_color(i));
		}
	}
	mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
}
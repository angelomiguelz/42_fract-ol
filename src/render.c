/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/08 17:22:02 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



unsigned int	get_color(int iterations)
{
	if (iterations == MAX_ITERATIONS)
		return(0x000000);
	return (0xFFFFFF);
}

void	render_mandelbrot()
{
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

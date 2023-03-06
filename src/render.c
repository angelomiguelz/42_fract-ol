/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/06 14:09:23 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



unsigned int	get_color(int iterations)
{
	if (iterations == MAX_ITERATIONS)
		return(0x000000);
	return (0xFFFFFF);
	/* else
	{
  		float t = (float)iterations / (float)MAX_ITERATIONS;
        int r = (int)(9 * (1 - t) * t * t * t * 255);
        int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
        return (r << 16) | (g << 8) | b;
	} */
}

int	get_iterations(double pixelr, double pixeli)
{
	if (data()->set == 1)
		return(mandelbrot(pixelr, pixeli));
	if (data()->set == 2)
		return(julia(pixelr, pixeli));
	return (0);
}

void	get_set_coords() // gets the complex plan coords to convert to pixels
{
	if (data()->set == MANDELBROT)
	{
		data()->r_max = 1;
		data()->r_min = -2;
		data()->i_max = 1;
		data()->i_min = -1;
	}
	if (data()->set == JULIA)
	{
		data()->r_min = -1.5;
		data()->r_max = 1.50;
		data()->i_min = -1.0;
		data()->i_max = 1.0;
	}
}

/* void	render_mandelbrot()
{
	int		x;
	int		y;
	double	pixelr;
	double	pixeli;
	int		iterations;

	//mlx_clear_window(data()->mlx, data()->window);

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pixelr = to_complex(x, 'R');
			pixeli = to_complex(y, 'I');

	
			//pixelr = 3.0 / WIDTH * x - 2;
			//pixeli = -2.0 / HEIGHT * y + 1;

			
			iterations = get_iterations(pixelr, pixeli);
			if (iterations == 0)
				printf("no iterations\n");
			my_mlx_pixel_put(x, y, get_color(iterations));	
		}
	}
	mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
} */

void	render_mandelbrot()
{
  //each iteration, it calculates: newz = oldz*oldz + p, where p is the current pixel, and oldz stars at the origin
  double pr, pi;           //real and imaginary part of the pixel p
  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
  double zoom = 1, moveX = -0.5, moveY = 0; //you can change these to zoom and change position
  int maxIterations = MAX_ITERATIONS;//after how much iterations the function should stop


  //loop through every pixel
  for(int y = 0; y < HEIGHT; y++)
  for(int x = 0; x < WIDTH; x++)
  {
    //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
    pr = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + moveX;
    pi = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + moveY;
    newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
    //"i" will represent the number of iterations
    int i;
    //start the iteration process
    for(i = 0; i < maxIterations; i++)
    {
      //remember value of previous iteration
      oldRe = newRe;
      oldIm = newIm;
      //the actual iteration, the real and imaginary part are calculated
      newRe = oldRe * oldRe - oldIm * oldIm + pr;
      newIm = 2 * oldRe * oldIm + pi;
      //if the point is outside the circle with radius 2: stop
      if((newRe * newRe + newIm * newIm) > 4) break;
    }
	if (i == MAX_ITERATIONS)
    	my_mlx_pixel_put(x, y, 0x000000);
	else
		my_mlx_pixel_put(x, y, 0xFFFFFF);
  }
  //make the Mandelbrot Set visible and wait to exit
  mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
}

void	render_julia()
{
	int		x;
	int		y;
	double	zr;
	double	zi;
	double	temp;
	double	moveX = 0;
	double	moveY = 0;
	unsigned int	color;
	int		i;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			//convert pixel coord to complex number (Re / Im)
			zr = 1.5 * (x - WIDTH / 2) / (0.5 * data()->zoomfactor * WIDTH) + moveX;
   			zi = (y - HEIGHT / 2) / (0.5 * data()->zoomfactor * HEIGHT) + moveY;

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
			if (i == MAX_ITERATIONS)
				color = 0x000000;
			else
				color = 0xFFFFFF;
			//color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < MAX_ITERATIONS)));
			my_mlx_pixel_put(x, y, color);	
		}
	}
	mlx_put_image_to_window(data()->mlx, data()->window, img()->img, 0, 0);
}
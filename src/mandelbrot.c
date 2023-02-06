/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:30:06 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/04 16:19:11 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	int 	iterations;
	double	zr;
	double	zi;
	double	tmp;

	iterations = 0;
	zr = 0;
	zi = 0;
	while (iterations < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
/* 		printf("iterations: %i\n", iterations);
		printf("cr: %f ci: %f\n", cr, ci);
		printf("zr: %f zi: %f\n", zr, zi); */
		iterations++;
	}
	return (iterations);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:30:06 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/10 13:39:19 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	int 	iterations;
	double	zr;
	double	zi;

	iterations = 0;
	//printf("\n CR: %f, CI: %f\n", cr, ci);
	while (iterations < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
/* 		printf("iterations: %i\n", iterations);
		printf("cr: %f ci: %f\n", cr, ci);
		printf("zr: %f zi: %f\n", zr, zi); */
		iterations++;
	}
	return (iterations);
}

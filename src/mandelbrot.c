/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:30:06 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/02 16:14:14 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	int 	iterations;
	double	zr;
	double	zi;

	iterations = 0;
	while (iterations < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		iterations++;
	}
	return (iterations);
}

/* int main(void)
{
	printf("%i\n", mandelbrot(10, 10));
} */
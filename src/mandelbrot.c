/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:30:06 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/25 19:54:25 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	int 	iterations;
	double	zr;
	double	zi;
	double	first_zi;

	iterations = 0;
	zi = 0.0;
	zr = 0.0;
	//printf("cr: %f  |  ci: %f\n", cr, ci);
	while (iterations < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		first_zi = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = first_zi;
		iterations++;
	}
	return (iterations);
}



/*

mandelbrot set equation: z = z^2 + c

(c) being the interest point or pixel.

numbers from -1 < z < 1 dont escape towards infite, therefor they are counted as
in the set and will be colored with black, all the rest if colored accordingly to
how quickly they escape (interatios). (0) being the attractive point and (1) the repulsive.

when adding the interest point the set orbit changes unpredictivly being 1 and -1 periodic,
(jumps between the point and zero).

examining other numbers, concludes that any number contained in the absolute value of 2 stays
inside the set and doenst .

being real numbers between -2 and 2
imaginary between -1 and 1.
*/
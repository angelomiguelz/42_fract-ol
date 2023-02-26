/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:28:22 by parallels         #+#    #+#             */
/*   Updated: 2023/02/26 16:36:51 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double cr, double ci)
{
	int 	iterations;
	double	zr;
	double	zi;
	double	first_zi;

	iterations = 0;
	zi = 0.0;
	zr = 0.0;
	//printf("cr: %f  |  ci: %f\n", cr, ci);
	while (iterations < 200)
	{
		if (fabs(zr) > 4.0)
			break ;
		first_zi = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = first_zi;
		iterations++;
	}
	return (iterations);
}
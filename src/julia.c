/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:28:22 by parallels         #+#    #+#             */
/*   Updated: 2023/03/06 13:48:41 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    julia_shift()
{
    data()->j_cr = to_complex(data()->mouse_x, 'R');
    data()->j_ci = to_complex(data()->mouse_y, 'I');
    render_julia();
}

int	julia(double zr, double zi)
{
	int 	iterations;
	double	first_zi;

	iterations = 0;
	//printf("cr: %f  |  ci: %f\n", cr, ci);
	while (iterations < MAX_ITERATIONS)
	{
		first_zi = 2 * zr * zi + data()->j_ci;
		zr = zr * zr - zi * zi + data()->j_cr;
		zi = first_zi;
		if (fabs(zr) > 4.0)
			break ;
		iterations++;
	}
	return (iterations);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:43:54 by parallels         #+#    #+#             */
/*   Updated: 2023/03/07 15:54:47 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*pixel;

	pixel = img()->addr + (y * img()->line_length + x * (img()->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

/* double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void applyZoom(double mouseRe, double mouseIm, double zoomFactor)
{
     double interpolation = 1.0 / zoomFactor;
     data()->r_min = interpolate(mouseRe, data()->r_min, interpolation);
     data()->i_min = interpolate(mouseIm, data()->i_min, interpolation);
     data()->r_max = interpolate(mouseRe, data()->r_max, interpolation);
     data()->i_max = interpolate(mouseIm, data()->i_max, interpolation);

	selector();
}

void	zoom(double zoomFactor)
{
	//printf("Mouse X: %i, Mouse Y: %i\n", mouse_x, mouse_y);
		
	double mouseRe = to_complex(data()->mouse_x, 'R');
	double mouseIm = to_complex(data()->mouse_y, 'I');

	applyZoom(mouseRe, mouseIm, zoomFactor);
} */
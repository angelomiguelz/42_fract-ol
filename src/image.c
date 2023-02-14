/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:43:54 by parallels         #+#    #+#             */
/*   Updated: 2023/02/13 15:03:39 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*pixel;
	if (!img()->addr)
	{
		printf("HERE");
		exit_();
	}
	pixel = img()->addr + (y * img()->line_length + x * (img()->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}



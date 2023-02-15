/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:00:42 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/15 15:05:08 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_()
{
	if (data()->mlx && data()->window)
	{
		mlx_destroy_window(data()->mlx, data()->window);
		mlx_loop_end(data()->mlx);
	}
	exit(0); /*TODO: Search better way to exit*/
	return (0);
}

void	start()
{
	data()->mlx = mlx_init();
	/* TODO: Protect if mlx was initialized or not */
	data()->window = mlx_new_window(data()->mlx, WIDTH, HEIGHT, "GABI E GAY");
	/* TODO: Protect if window was initialized or not */
	//img()->img = mlx_new_image(data()->mlx, WIDTH, HEIGHT);
	//img()->addr = mlx_get_data_addr(img()->img, &img()->bits_per_pixel, &img()->line_length, &img()->endian);
}

void	error_help()
{
	printf("TUA MAE\n");
	exit_(0);
}
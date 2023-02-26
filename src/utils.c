/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:00:42 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/26 17:15:04 by parallels        ###   ########.fr       */
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
	exit(0);
	return (0);
}

void	start()
{
	data()->mlx = mlx_init();
	data()->window = mlx_new_window(data()->mlx, WIDTH, HEIGHT, "GABI E GAY");
	img()->img = mlx_new_image(data()->mlx, WIDTH, HEIGHT);
	img()->addr = mlx_get_data_addr(img()->img, &img()->bits_per_pixel, &img()->line_length, &img()->endian);
}

void	error_help()
{
	printf("TUA MAE\n");
	printf("Mete o M à frente\n");
	printf("\n");

	exit_();
}

void	get_info(char *av)
{
	if(av[0] == 'J')
	{
		data()->set = JULIA;
		printf("JULIA\n");
		return;
	}
	if(av[0] == 'M')
	{
		data()->set = MANDELBROT;
		printf("MANDELBROT\n");
		return;
	}
	else
		error_help();
}
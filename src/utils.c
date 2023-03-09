/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:00:42 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/09 17:08:05 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_()
{
	if (data()->mlx && data()->window)
	{
		mlx_destroy_image(data()->mlx, img()->img);
		mlx_destroy_window(data()->mlx, data()->window);
		mlx_loop_end(data()->mlx);
		//free(data()->mlx);
		//free(data()->window);
		//free(img()->img);
		//free(img()->addr);
	}
	exit(0);
	return (0);
}

void	start()
{
	data()->mlx = mlx_init();
	data()->window = mlx_new_window(data()->mlx, WIDTH, HEIGHT, "Fract-ol mzarichn");
	img()->img = mlx_new_image(data()->mlx, WIDTH, HEIGHT);
	img()->addr = mlx_get_data_addr(img()->img, &img()->bits_per_pixel, &img()->line_length, &img()->endian);

	data()->zoomfactor = 1.0;
	data()->j_cr = -0.7;
    data()->j_ci = 0.27015;
	data()->move_x = 0.0;
	data()->move_y = 0.0;
	img()->color = 1;
}

void	error_help()
{
	ft_printf("To use the fract-ol first choose the fractal:\n");
	ft_printf("\n");
	ft_printf("./fractol mandelbrot -> for the mandelbrot set.\n");
	ft_printf("./fractol julia -> for the julia set.\n");
	ft_printf("\n");
	ft_printf("Zoom: Scroll Up/I (zoom in) | Down/O (zoom out).\n");
	ft_printf("Move: Arrow Keys.");
	ft_printf("\n");
	ft_printf("Change Fractals: 1 - Mandelbrot , 2 - Julia.\n");
	ft_printf("Change julia parameters: Mouse Click on the zone.\n");
	ft_printf("\n");

	exit_();
}

int		ft_strncmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	get_info(char **av)
{
	if(ft_strncmp(av[1], "julia") == 0)
	{
		data()->set = JULIA;
		return;
	}
	if(ft_strncmp(av[1], "mandelbrot") == 0)
	{
		data()->set = MANDELBROT;
		return;
	}
	else
		error_help();
}
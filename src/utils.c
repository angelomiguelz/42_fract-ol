/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:00:42 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/03 18:46:35 by parallels        ###   ########.fr       */
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
	image_init();
	get_set_coords();
}

void	error_help()
{
	printf("TUA MAE\n");
	printf("Mete o M à frente\n");
	printf("\n");

	exit_();
}

double	to_complex(double coord, char flag)
{
	if (flag == 'R')
		coord = data()->r_min + (double)coord * (data()->r_max - data()->r_min) / WIDTH;
	if (flag == 'I')
		coord = data()->i_max + (double)coord * (data()->i_min - data()->i_max) / HEIGHT;
	return (coord);	
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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(((char *)s) + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc (size * count);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:00:42 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/08 15:24:08 by mzarichn         ###   ########.fr       */
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

	data()->zoomfactor = 1.0;
	data()->mouse_x = WIDTH/2;
	data()->mouse_y = HEIGHT/2;
	data()->j_cr = -0.7;
    data()->j_ci = 0.27015;
	data()->move_x = 0.0;
	data()->move_y = 0.0;
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
	if(av[0] == 'K')
	{
		data()->set = MANDELBOX;
		printf("MANDELBOX\n");
		return;
	}
	else
		error_help();
}

/* double	to_complex(double coord, char flag)
{
	if (flag == 'R')
		coord = data()->r_min + (double)coord * (data()->r_max - data()->r_min) / WIDTH;
	if (flag == 'I')
		coord = data()->i_max + (double)coord * (data()->i_min - data()->i_max) / HEIGHT;
	return (coord);	
} */

/* void	ft_bzero(void *s, size_t n)
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
} */
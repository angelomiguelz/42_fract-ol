/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:00:42 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/05 16:39:21 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_exit(t_data *fractol)
{
	if (fractol->mlx && fractol->window)
	{
		mlx_destroy_window(fractol->mlx, fractol->window);
		mlx_loop_end(fractol->mlx);
	}
	exit(0); /*TODO: Search better way to exit*/
	return (0);
}

/*Puts default data into the structure for protection and debugging purposes*/
void	default_data(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
	data->f_set = MANDELBROT;
	data->image.img = NULL;
	data->buf = NULL;
	data->r_min = 0;
	data->r_max = 0;
	data->i_min = 0;
	data->i_max = 0;
	data->image.palette = NULL;
	data->image.color_pattern = -1;
	data->image.color = 0;
}

/*A clenear and more complete init and window starter with protections*/
void	start(t_data *data)
{
	data->mlx = mlx_init();
	/* TODO: Protect if mlx was initialized or not */
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "GABI E GAY");
	/* TODO: Protect if window was initialized or not */


	//set configurations
	data->r_min = -2.0;
	data->r_max = 1.0;
	data->i_max = -1.5;
	data->i_min = data->i_max + (data->r_max - data->r_min) * HEIGHT / WIDTH;

	color_shift(data);
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
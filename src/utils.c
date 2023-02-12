/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:00:42 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/09 14:58:10 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_(t_data *fractol)
{
	if (fractol->mlx && fractol->window)
	{
		mlx_destroy_window(fractol->mlx, fractol->window);
		mlx_loop_end(fractol->mlx);
	}
	exit(0); /*TODO: Search better way to exit*/
	return (0);
}

void	start(t_data *data)
{
	data->mlx = mlx_init();
	/* TODO: Protect if mlx was initialized or not */
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "GABI E GAY");
	/* TODO: Protect if window was initialized or not */
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
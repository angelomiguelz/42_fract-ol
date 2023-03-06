/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:32:03 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/13 14:13:44 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*data(void)
{
	static t_data data;
	return (&data);
}

t_img	*img(void)
{
	static t_img img;
	return (&img);
}

void	selector()
{
	if (data()->set == MANDELBROT)
		render_mandelbrot();
	if (data()->set == JULIA)
		render_julia();
}

int main(int ac, char **av)
{
	(void)av;
	(void)ac;
	if (ac == 2)
	{
		printf("%s\n", av[1]);

		data()->zoomfactor = 1;
		data()->mouse_x = WIDTH/2;
		data()->mouse_y = HEIGHT/2;
		data()->j_cr = -0.7;
    	data()->j_ci = 0.27015;

		get_info(av[1]);
		start();
		selector();

		mlx_key_hook(data()->window, key_handler, data());
		mlx_hook(data()->window, EVENT_CLOSE_BTN, 0, exit_, data());
		mlx_loop(data()->mlx);
	}
	else
		error_help();
	return (0);
}

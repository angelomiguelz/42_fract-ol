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


int main(int ac, char **av)
{
	(void)av;
	(void)ac;
	start();
	render();

	mlx_key_hook(data()->window, key_handler, data());
	mlx_hook(data()->window, EVENT_CLOSE_BTN, 0, exit_, data());
	mlx_loop(data()->mlx);

	return (0);
}

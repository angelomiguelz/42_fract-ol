/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:32:03 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/09 15:01:55 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int main(int ac, char **av)
{
	t_data	fractol;
	(void)av;
	if (ac == 2)
	{
		start(&fractol); //Inittialization of MLX
		render(&fractol);


		mlx_key_hook(fractol.window, key_handler, &fractol);
		mlx_hook(fractol.window, EVENT_CLOSE_BTN, 0, exit_, &fractol);
		mlx_loop(fractol.mlx);
	}
	else
		error_help(&fractol);
	return (0);
}

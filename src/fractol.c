/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:32:03 by mzarichn          #+#    #+#             */
/*   Updated: 2023/01/31 13:57:33 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int main(int ac, char **av)
{
	t_data	fractol;

	if (ac < 2)
		help_msg(&fractol);
	(void)av;
	
	default_data(&fractol);
	start_init(&fractol);

	mlx_key_hook(fractol.window, key_handler, &fractol);
	mlx_hook(fractol.window, EVENT_CLOSE_BTN, 0, clean_exit, &fractol);
	mlx_loop(fractol.mlx);
}
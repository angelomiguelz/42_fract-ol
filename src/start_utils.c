/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/01/31 14:26:25 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*Puts default data into the structure for protection and debugging purposes*/
void	default_data(t_data *data)
{
	data->mlx = NULL;
	data->window = NULL;
}

/*A clenear and more complete init and window starter with protections*/
void	start_init(t_data *data)
{
	data->mlx = mlx_init();
	/* TODO: Protect if mlx was initialized or not */
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "GABI E GAY");
	/* TODO: Protect if window was initialized or not */
}
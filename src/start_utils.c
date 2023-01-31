/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:06:15 by mzarichn          #+#    #+#             */
/*   Updated: 2023/01/30 18:31:48 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*Puts default data into the structure for protection and debugging purposes*/
void	default_data(t_data *f)
{
	/* data->mlx = NULL;
	data->window = NULL; */

	f->mlx = NULL;
	f->window = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->set = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->kr = 0;
	f->ki = 0;
	f->sx = 0;
	f->rx = 0;
	f->fx = 0;
	f->palette = NULL;
	f->color_pattern = -1;
	f->color = 0;
}

/*A clenear and more complete init and window starter with protections*/
void	start_init(t_data *data)
{
	data->mlx = mlx_init();
	/* TODO: Protect if mlx was initialized or not */
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "GABI E GAY");
	/* TODO: Protect if window was initialized or not */
}
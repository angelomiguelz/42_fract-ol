/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:31:52 by mzarichn          #+#    #+#             */
/*   Updated: 2023/01/31 14:04:04 by mzarichn         ###   ########.fr       */
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

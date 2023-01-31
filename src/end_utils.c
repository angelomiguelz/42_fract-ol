/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:31:52 by mzarichn          #+#    #+#             */
/*   Updated: 2023/01/30 15:46:18 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_exit(t_data *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->window);
	mlx_loop_end(fractol->mlx);

	return (0);
}

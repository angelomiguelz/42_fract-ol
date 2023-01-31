/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:31 by mzarichn          #+#    #+#             */
/*   Updated: 2023/01/30 16:36:07 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key, t_data *mlx)
{
	if (key == ESC_KEY)
	{
		clean_exit(mlx);
		return (0);
	}
	if (key == MOUSE_WHEEL_UP)
		printf("Mouse Up\n");
	if (key == MOUSE_WHEEL_DOWN)
		printf("Mouse Down\n");
	if (key == KEY_A)
		printf("Key A\n");
	if (key == KEY_W)
		printf("Key W\n");
	if (key == KEY_S)
		printf("Key S\n");
	if (key == KEY_D)
		printf("Key D\n");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:43:54 by parallels         #+#    #+#             */
/*   Updated: 2023/02/09 14:37:21 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void	init_img(t_data *data)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	data->image.palette = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
    if (!data->image.palette)
    {
        printf("\nHERE\n");
        exit(0);
    }
	data->image.img = mlx_new_image(data->mlx , WIDTH, HEIGHT);
    if (!data->image.img)
    {
        printf("\nHERE\n");
        exit(0);
    }
	buf = mlx_get_data_addr(data->image.img, &pixel_bits, &line_bytes, &endian);
	data->buf = buf;
}

/* reinit_image:
*	Cleanly reinitializes the MLX image if the color palette or 
*	fractal type is modified at runtime.
*/
void	reinit_img(t_data *data)
{
	if (data->mlx && data->image.img)
		mlx_destroy_image(data->mlx, data->image.img);
	if (data->image.palette)
		free(data->image.palette);
	if (data->buf)
		data->buf = NULL;
	init_img(data);
}

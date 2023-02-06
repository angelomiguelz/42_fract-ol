/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:43:54 by parallels         #+#    #+#             */
/*   Updated: 2023/02/05 16:41:32 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_shift_special(t_data *data)
{
	int	alt_color;

	if (data->image.color == 0xFFFFFF)
		alt_color = 0xCCCCCC;
	else
		alt_color = data->image.color;

    (void)alt_color;
}

/* color_shift_striped:
*	Extension of the color_shift function. Changes the color pattern.
*	The fractal can then be rendered again with different color
*	effects.
*/
static void	color_shift_striped(t_data *data)
{
	color_shift_special(data);
}


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

static int	interpolate(int startcolor, int endcolor, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((startcolor >> 16) & 0xFF);
	start_rgb[1] = ((startcolor >> 8) & 0xFF);
	start_rgb[2] = ((startcolor >> 0) & 0xFF);
	end_rgb[0] = ((endcolor >> 16) & 0xFF);
	end_rgb[1] = ((endcolor >> 8) & 0xFF);
	end_rgb[2] = ((endcolor >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

void	set_color_mono(t_data *data, int color)
{
	int		i;
	int		j;
	double	fraction;
	int		color1;
	int		color2;

	color1 = 0x000000;
	color2 = color;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while (j < MAX_ITERATIONS / 2)
		{
			fraction = (double)j / (MAX_ITERATIONS / 2);
			data->image.palette[i + j] = interpolate(color1, color2, fraction);
			j++;
		}
		color1 = color2;
		color2 = 0xFFFFFF;
		i += j;
	}
	data->image.palette[MAX_ITERATIONS -1] = 0;
}

void	set_color_multiple(t_data *data, int colors[4], int n)
{
	int		i;
	int		j;
	int		x;
	double	fraction;

	i = 0;
	x = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while ((i + j) < MAX_ITERATIONS && j < (MAX_ITERATIONS / (n - 1)))
		{
			fraction = (double)j / (MAX_ITERATIONS / (n - 1));
			data->image.palette[i + j] = interpolate(colors[x], colors[x + 1], fraction);
			j++;
		}
		x++;
		i += j;
	}
	data->image.palette[MAX_ITERATIONS - 1] = 0;
}

int	get_percent_color(int color, double percent)
{
	int		rgb[3];
	int		trgb[3];
	double	percentage;

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	percentage = (percent / 100) * 256;
	trgb[0] = (rgb[0] + percentage) - 256;
	trgb[1] = (rgb[1] + percentage) - 256;
	trgb[2] = (rgb[2] + percentage) - 256;
	return (0xFF << 24 | trgb[0] << 16 | trgb[1] << 8 | trgb[2]);
}

void	color_shift(t_data *data)
{
	int	alt_color;

	data->image.color_pattern = (data->image.color_pattern + 1) % 9;
	reinit_img(data);
	if (data->image.color == 0x000000)
		alt_color = 0x333333;
	else
		alt_color = data->image.color;
	if (data->image.color_pattern == 0)
		set_color_mono(data, alt_color);
	else if (data->image.color_pattern == 1)
		set_color_multiple(data, (int [4]){0x000000, alt_color,
			get_percent_color(data->image.color, 50), 0xFFFFFF}, 4);
	else
		color_shift_striped(data);
}
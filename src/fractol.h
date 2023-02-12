/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:39 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/09 15:01:27 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx-linux/mlx.h"
#include "../ft_printf/ft_printf.h"
#include "key_handler.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/* Dimensions */
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 50

/* sets */
# define MANDELBROT 1

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*window;
	t_img	image;
	char	f_set;
	double	r_min;
	double	r_max;
	double	i_min;
	double	i_max;	
	char	*buf;

}	t_data;


void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		exit_(t_data *f);
int		key_handler(int key, t_data *mlx);
void	start(t_data *data);
void	error_help(t_data *fractol);
void	render(t_data *data);
int		mandelbrot(double cr, double ci);

#endif
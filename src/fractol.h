/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:39 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/14 11:15:29 by parallels        ###   ########.fr       */
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
	int		line_length;
	int		endian;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*window;
	char	f_set;
	double	r_min;
	double	r_max;
	double	i_min;
	double	i_max;	
	char	*buf;

}	t_data;


t_data	*data(void);
t_img	*img(void);

int		exit_();
int		key_handler(int key);
void	start();
void	error_help();
void	render();
int		mandelbrot(double cr, double ci);
void	my_mlx_pixel_put(int x, int y, int color);
void	render_2();


#endif
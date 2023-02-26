/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:39 by mzarichn          #+#    #+#             */
/*   Updated: 2023/02/26 17:00:21 by parallels        ###   ########.fr       */
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
# define HEIGHT 600
# define MAX_ITERATIONS 100

/* sets */
# define MANDELBROT 1
# define JULIA 2


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
	int		set;
	void	*mlx;
	void	*window;
	char	f_set;
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
int		julia(double cr, double ci);
void	get_info(char *av);


#endif
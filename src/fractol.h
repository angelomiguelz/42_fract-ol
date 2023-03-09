/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:39 by mzarichn          #+#    #+#             */
/*   Updated: 2023/03/09 16:58:57 by parallels        ###   ########.fr       */
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
# define WIDTH 1400
# define HEIGHT 900
# define MAX_ITERATIONS 200

/* sets */
# define MANDELBROT 1
# define JULIA 2
# define MANDELBOX 3



typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
}	t_img;

typedef struct s_data {
	int		set;
	void	*mlx;
	void	*window;
	char	f_set;

	double	j_cr;
	double	j_ci;
	double  zoomfactor;
	double	move_x;
	double	move_y;
}	t_data;


t_data	*data(void);
t_img	*img(void);

int		exit_();
int		key_handler(int key);
void	start();
void	error_help();
void	my_mlx_pixel_put(int x, int y, int color);
void	get_info(char **av);
void	image_init();
void	render_julia();
void	render_mandelbrot();
void	selector();


#endif
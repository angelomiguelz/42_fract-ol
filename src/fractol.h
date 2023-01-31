/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:39 by mzarichn          #+#    #+#             */
/*   Updated: 2023/01/30 18:28:26 by mzarichn         ###   ########.fr       */
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
# define WIDTH 600
# define HEIGHT 600
# define MAX_ITERATIONS 60

/* sets */
# define MANDELBROT 1



typedef struct s_data {
	void	*mlx;
	void	*window;


	void	*img;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
	int		*palette;
	int		color_pattern;
	int		color;

}	t_data;


void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int	clean_exit(t_data *f);
int		key_handler(int key, t_data *mlx);
void	default_data(t_data *data);
void	start_init(t_data *data);
void	help_msg(t_data *fractol);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:49:30 by mdias             #+#    #+#             */
/*   Updated: 2024/03/01 19:20:42 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	select_fractal(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		fractal->c.real = (drand48() * 1.2) - 0.8;
		fractal->c.i = (drand48() * 1.4) - 0.7;
		initialize_julia(fractal, fractal->c.real, fractal->c.i);
	}
	else if (fractal->type == JULIA)
		initialize_tricorn(fractal);
	else if (fractal->type == TRICORN)
		initialize_mandelbroat(fractal);
	else
		initialize_mandelbroat(fractal);
	mlx_set_window_title(fractal->mlx, fractal->name);
}

void	fractal_init(t_fractal *fractal, int type, double c_x, double c_y)
{
	if (type == MANDELBROT)
		initialize_mandelbroat(fractal);
	if (type == JULIA)
		initialize_julia(fractal, c_x, c_y);
	if (type == TRICORN)
		initialize_tricorn(fractal);
	controls_msg();
	fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	if (!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_terminate(fractal->mlx);
		exit(EXIT_FAILURE);
	}
}

void	render_fractal_type(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		mandelbrot_render(fractal);
	}
	if (fractal->type == JULIA)
	{
		julia_render(fractal);
	}
	if (fractal->type == TRICORN)
	{
		tricorn_render(fractal);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:49:30 by mdias             #+#    #+#             */
/*   Updated: 2024/03/03 15:32:01 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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

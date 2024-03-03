/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:11:55 by mdias             #+#    #+#             */
/*   Updated: 2024/03/02 21:12:38 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initialize_julia(t_fractal *fractal, double c_x, double c_y)
{
	fractal->name = "Julia";
	fractal->type = JULIA;
	fractal->color = PURPLE;
	fractal->color2 = ORANGE;
	fractal->escape_value = 4.0;
	fractal->iterations_def = ESCAPE_COUNT;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->initial_zoom = 1;
	fractal->zoom = 1.0;
	fractal->c.real = c_x;
	fractal->c.i = c_y;
	fractal->xmin = -2.0 * fractal->initial_zoom;
	fractal->xmax = 2.0 * fractal->initial_zoom;
	fractal->ymin = -2.0 * fractal->initial_zoom;
	fractal->ymax = 2.0 * fractal->initial_zoom;
}

void	julia_pixels(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	unsigned int	i;

	i = 0;
	z.real = ((x - 0) * (fractal->xmax - fractal->xmin)) / (WIDTH - 0)
		+ fractal->xmin + fractal->shift_x;
	z.i = ((y - 0) * (fractal->ymax - fractal->ymin)) / (HEIGHT - 0)
		+ fractal->ymin + fractal->shift_y;
	while (i < fractal->iterations_def)
	{
		z = complex_sum(complex_square(z), fractal->c);
		if ((((z.real * z.real) + (z.i * z.i)) < fractal->escape_value))
			mlx_put_pixel(fractal->img, x, y, fractal->color * 0.9995);
		else if ((z.real * z.real + z.i * z.i) > fractal->escape_value)
		{
			fractal->color2 = color_iteration_mapping(i, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color2);
			return ;
		}
		i++;
	}
}

void	julia_render(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			julia_pixels(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

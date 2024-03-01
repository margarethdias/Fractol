/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:51:06 by mdias             #+#    #+#             */
/*   Updated: 2024/03/01 17:38:40 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initialize_tricorn(t_fractal *fractal)
{
	fractal->name = "Tricorn";
	fractal->color = ORANGE;
	fractal->type = TRICORN;
	fractal->escape_value = 4.0;
	fractal->iterations_def = ESCAPE_COUNT;
	fractal->shift_x = -0.1;
	fractal->shift_y = 0.0;
	fractal->initial_zoom = 0.95;
	fractal->zoom = 1.0;
	fractal->xmin = -2.0 * fractal->initial_zoom;
	fractal->xmax = 2.0 * fractal->initial_zoom;
	fractal->ymin = -2.0 * fractal->initial_zoom;
	fractal->ymax = 2.0 * fractal->initial_zoom;
}

void	tricorn_pixels(int x, int y, t_fractal *fractal)
{
	t_complex		z;
	t_complex		c;
	unsigned int	i;

	i = 0;
	z.real = 0.0;
	z.i = 0.0;
	c.real = ((fractal->xmax - fractal->xmin) * (x - 0))
		/ (WIDTH - 0) + fractal->xmin + fractal->shift_x;
	c.i = ((fractal->ymax - fractal->ymin) * (y - 0))
		/ (HEIGHT - 0) + fractal->ymin + fractal->shift_y;
	while (i < fractal->iterations_def)
	{
		z = (complex_sum(complex_conjugate((complex_square(z))), c));
		if (((z.real * z.real) + (z.i * z.i)) < fractal->escape_value)
			mlx_put_pixel(fractal->img, x, y, reduce_color_intensity(fractal));
		else if (((z.real * z.real) + (z.i * z.i)) > fractal->escape_value)
		{
			fractal->color2 = color_iteration_mapping(i, fractal);
			mlx_put_pixel(fractal->img, x, y, fractal->color2);
			return ;
		}
		i++;
	}
}

void	tricorn_render(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			tricorn_pixels(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:27:29 by mdias             #+#    #+#             */
/*   Updated: 2024/01/30 23:08:57 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	
	i = 0;
	z.real = 0.0;
	z.i = 0.0;
	
	c.real = map(x, -2, 2, 0, WIDTH);
	c.i = map(y, 2, -2, 0, HEIGHT);

	while (i < fractal->iterations_def)
	{
		z = complex_sum(complex_square(z), c);
		if ((z.real * z.real) + (z.i * z.i) > fractal->escape_value)
		{
			// fractal->color = map(i, BLACK, WHITE, 0, fractal->iterations_def);
			fractal->color = WHITE;
			mlx_put_pixel(fractal->img, x, y, fractal->color);
			return;
		}
	    ++i;
	}	
	mlx_put_pixel(fractal->img, x, y, PURPLE);

}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0,0);
}
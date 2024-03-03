/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:14:46 by mdias             #+#    #+#             */
/*   Updated: 2024/03/03 15:32:49 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = param;
	xdelta = 0;
	mlx_get_mouse_pos(fractal->mlx, &fractal->mouse_x, &fractal->mouse_y);
	fractal->xzoom = fractal->xmin + fractal->mouse_x * ((fractal->xmax
				- fractal->xmin) / WIDTH);
	fractal->yzoom = fractal->ymin + fractal->mouse_y * ((fractal->ymax
				- fractal->ymin) / HEIGHT);
	if (fractal->type == JULIA && mlx_is_key_down(fractal->mlx,
			MLX_KEY_LEFT_SHIFT))
	{
		fractal->c.real += (ydelta / 400) * fractal->zoom;
		fractal->c.i += (ydelta / 400) * fractal->zoom;
		render_fractal_type(fractal);
	}
	else if (ydelta != 0)
	{
		zoom(ydelta, fractal);
		render_fractal_type(fractal);
	}
}

void	cursorhook(double xmouse, double ymouse, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	xmouse = 0;
	ymouse = 0;
	mlx_get_mouse_pos(fractal->mlx, &fractal->mouse_x,
		&fractal->mouse_y);
	if (fractal->type == JULIA
		&& mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT_CONTROL))
	{
		fractal->c.real = ((fractal->mouse_x) * (fractal->xmax - fractal->xmin)
				* 0.9) / (WIDTH) + (fractal->xmin * 0.9) + fractal->shift_x;
		fractal->c.i = ((fractal->mouse_y) * (fractal->ymax - fractal->ymin)
				* 0.9) / (HEIGHT) + (fractal->ymin * 0.9) + fractal->shift_y;
		render_fractal_type(fractal);
	}
}

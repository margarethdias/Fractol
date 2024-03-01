/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:19:57 by mdias             #+#    #+#             */
/*   Updated: 2024/03/01 19:27:25 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	keyboard_arrows(t_fractal *fractal)
{
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
	{
		fractal->shift_y -= 0.5 * fractal->zoom;
		render_fractal_type(fractal);
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
	{
		fractal->shift_y += 0.5 * fractal->zoom;
		render_fractal_type(fractal);
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
	{
		fractal->shift_x -= 0.5 * fractal->zoom;
		render_fractal_type(fractal);
	}
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
	{
		fractal->shift_x += 0.5 * fractal->zoom;
		render_fractal_type(fractal);
	}
}

void	keyhook(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	keyboard_arrows(fractal);
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(fractal->mlx);
	}
}

void	zoom(double ydelta, t_fractal *fr)
{
	double	zoom_factor;

	zoom_factor = 1.1;
	if (ydelta > 0)
	{
		fr->zoom *= 0.9;
		fr->xmin = fr->xzoom - (1.0 / zoom_factor) * (fr->xzoom - fr->xmin);
		fr->xmax = fr->xzoom + (1.0 / zoom_factor) * (fr->xmax - fr->xzoom);
		fr->ymin = fr->yzoom - (1.0 / zoom_factor) * (fr->yzoom - fr->ymin);
		fr->ymax = fr->yzoom + (1.0 / zoom_factor) * (fr->ymax - fr->yzoom);
	}
	else if (ydelta < 0)
	{
		fr->zoom *= 1.1;
		fr->xmin = fr->xzoom - zoom_factor * (fr->xzoom - fr->xmin);
		fr->xmax = fr->xzoom + zoom_factor * (fr->xmax - fr->xzoom);
		fr->ymin = fr->yzoom - zoom_factor * (fr->yzoom - fr->ymin);
		fr->ymax = fr->yzoom + zoom_factor * (fr->ymax - fr->yzoom);
	}
}

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

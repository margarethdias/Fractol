/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:19:57 by mdias             #+#    #+#             */
/*   Updated: 2024/03/01 17:46:12 by mdias            ###   ########.fr       */
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
	double		zoom_factor;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:19:57 by mdias             #+#    #+#             */
/*   Updated: 2024/01/31 22:51:43 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

static void	keyboard_arrows(t_fractal *fractal)
{
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_UP))
	{
		fractal->shift_y -= 0.3;
		fractal_render(fractal);
	}
		if (mlx_is_key_down(fractal->mlx, MLX_KEY_DOWN))
	{
		fractal->shift_y += 0.3;
		fractal_render(fractal);
	}
		if (mlx_is_key_down(fractal->mlx, MLX_KEY_LEFT))
	{
		fractal->shift_x -= 0.3;
		fractal_render(fractal);
	}
		if (mlx_is_key_down(fractal->mlx, MLX_KEY_RIGHT))
	{
		fractal->shift_x += 0.3;
		fractal_render(fractal);
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

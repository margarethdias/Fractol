/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:49:30 by mdias             #+#    #+#             */
/*   Updated: 2024/01/29 22:46:06 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

void	data_init(t_fractal	*fractal)
{
	fractal->escape_value = 4; // 2 ^ 2 my hypotenus
	fractal->iterations_def = 42;
}
void	fractal_init(t_fractal	*fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	if(!fractal->mlx)
		exit(EXIT_FAILURE);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_terminate(fractal->mlx);
		exit(EXIT_FAILURE);
	}
	data_init(fractal);
}
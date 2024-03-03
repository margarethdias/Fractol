/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:30:09 by mdias             #+#    #+#             */
/*   Updated: 2024/03/02 19:47:23 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static bool	check_input(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		fractal_init(fractal, MANDELBROT, 0, 0);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (ft_atod(argv[2]) >= -2.0 && ft_atod(argv[2]) <= 2.0
			&& ft_atod(argv[3]) >= -2.0 && ft_atod(argv[3]) <= 2.0)
			fractal_init(fractal, JULIA, ft_atod(argv[2]), ft_atod(argv[3]));
		else
			return (false);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "tricorn", 7))
		fractal_init(fractal, TRICORN, 0, 0);
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbox", 9))
		fractal_init(fractal, MANDELBOX, 0, 0);
	else
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (check_input(argc, argv, &fractal))
	{
		render_fractal_type(&fractal);
		mlx_loop_hook(fractal.mlx, keyhook, &fractal);
		mlx_scroll_hook(fractal.mlx, &scrollhook, &fractal);
		mlx_cursor_hook(fractal.mlx, &cursorhook, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		param_error();
		return (EXIT_FAILURE);
	}
	mlx_delete_image(fractal.mlx, fractal.img);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}

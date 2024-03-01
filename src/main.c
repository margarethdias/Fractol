/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:30:09 by mdias             #+#    #+#             */
/*   Updated: 2024/02/05 20:58:05 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int main(int argc, char **argv)
{
	t_fractal	fractal;
	//mlx_t		*mlx;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) 
		|| (argc == 2 && !ft_strncmp(argv[1], "julia", 6)))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);	
	
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

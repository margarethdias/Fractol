/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:30:09 by mdias             #+#    #+#             */
/*   Updated: 2024/01/25 00:36:10 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

int main(int argc, char **argv)
{
	t_fractal	fractal;
	mlx_t		*mlx;
	
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11) 
		|| argc == 2 && !ft_strncmp(argv[1], "julia", 6))
	{
			
	}
	else
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

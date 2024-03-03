/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:05:48 by mdias             #+#    #+#             */
/*   Updated: 2024/03/03 16:13:02 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_msg(void)
{
	const char	*error_str;

	error_str = mlx_strerror(mlx_errno);
	if (error_str)
	{
		ft_putendl_fd(error_str, 1);
	}
	exit(EXIT_FAILURE);
}

void	param_error(void)
{
	ft_putendl_fd("\n\nError - incorrect params\n\n", 1);
	ft_putendl_fd("params:\t mandelbrot", 1);
	ft_putendl_fd("\ttricorn", 1);
	ft_putendl_fd("\tjulia <real> <imaginary>", 1);
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("examples:", 1);
	ft_putendl_fd("./fractol julia -0.4 0.06", 1);
	ft_putendl_fd("./fractol julia 0.285 0.01", 1);
	ft_putendl_fd("./fractol julia -0.8 0.156", 1);
}

void	controls_msg(void)
{
	ft_putendl_fd("Controls:", 1);
	ft_putendl_fd("\tpress ESC to exit", 1);
	ft_putendl_fd("\tpress arrow keys to move", 1);
	ft_putendl_fd("\tuse mouse scroll for zoom", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Julia Set constants:", 1);
	ft_putendl_fd("\tleft_shift + scroll to increase or decrease", 1);
	ft_putendl_fd("\tleft_ctrl + mouse change constants based on mouse move", 1);
}

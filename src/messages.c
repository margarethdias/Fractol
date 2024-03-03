/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:05:48 by mdias             #+#    #+#             */
/*   Updated: 2024/03/02 21:00:07 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// void	error_msg(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

void	help_msg(void)
{
	ft_putendl_fd("\n+==========================================+", 1);
	ft_putendl_fd("|                 FRACT'OL                 |", 1);
	ft_putendl_fd("+==========================================+\n", 1);
	// ft_putendl_fd(mlx_sterror(mlx_errno), 1);
	param_error();
	exit(EXIT_FAILURE);
}
// void	controls_msg(void)
// {
// 	puts("Controls:\n" \
// 	"\tpress \033[1m\033[38;5;110mESC\033[0m to exit\n" \
// 	"\tpress \033[1m\033[38;5;110marrow keys\033[0m to move\n" \
// 	"\tuse \033[1m\033[38;5;110mmouse scroll\033[0m for zoom\n" \
// 	"\tpress \033[1m\033[38;5;110mC\033[0m to change color\n" \
// 	"\nJulia Set constants:\n" \
// 	"\tuse \033[1m\033[38;5;110mleft_shift + scroll\033[0m " \
// 	"to increase or decrease\n" \
// 	"\tuse \033[1m\033[38;5;110mleft_ctrl + mouse \033[0m"\
// 	"to change constants based on relative mouse position\n");
// }

// void	param_error(void)
// {
// 	puts("\n\nError - incorrect params\n\n" \
// "params:\t \033[1m\033[38;5;110mmandelbrot\n" \
// "\t \033[1m\033[38;5;110mtricorn\n" \
// "\t julia \033[0m\033[38;5;115m<real> <imaginary>\033[0m\n\n" \
// "examples:\n" \
// "./fractol julia \033[38;5;115m0.285 0.01\033[0m\n" \
// "./fractol julia \033[38;5;115m-0.8 0.156\n");
// }


void	param_error(void)
{
	ft_putendl_fd("+==========  Available Fractals  ==========+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tMandelbrot", 1);
	ft_putendl_fd("\tJulia", 1);
	ft_putendl_fd("\tTricorn", 1);
	ft_putendl_fd("\tMandelbox", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	
}

void	controls_msg(void)
{
	ft_putendl_fd("\n+============  Controls  ======================+", 1);
	ft_putendl_fd("arrow keys\tmove view.", 1);
	ft_putendl_fd("mouse scroll wheel\tzoom in and out.", 1);
	ft_putendl_fd("ESC or close window\tquit fract'ol.", 1);
	ft_putendl_fd("**Julia Set**\t\t", 1);
	ft_putendl_fd("Left shit + scroll\t\tincrease and decrease.", 1);
	ft_putendl_fd("Left ctrl + mouse\t\tchange constants based on relative mouse position", 1);
	ft_putendl_fd("+==============================================+\n", 1);
}

// void	help_msg(t_fractal *fractal)
// {
// 	ft_putendl_fd("\n+==========================================+", 1);
// 	ft_putendl_fd("|                 FRACT'OL                 |", 1);
// 	ft_putendl_fd("+==========================================+\n", 1);
// 	param_error();
// 	clean_exit(EXIT_FAILURE, fractal);
// }
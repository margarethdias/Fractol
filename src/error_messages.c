/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:05:48 by mdias             #+#    #+#             */
/*   Updated: 2024/03/01 17:34:05 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_msg(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	controls_msg(void)
{
	puts("Controls:\n" \
	"\tpress \033[1m\033[38;5;110mESC\033[0m to exit\n" \
	"\tpress \033[1m\033[38;5;110marrow keys\033[0m to move\n" \
	"\tuse \033[1m\033[38;5;110mmouse scroll\033[0m for zoom\n" \
	"\tpress \033[1m\033[38;5;110mTAB\033[0m to change fractal\n" \
	"\tpress \033[1m\033[38;5;110mC\033[0m to change color\n" \
	"\t keep \033[1m\033[38;5;110mG\033[0m pressed for glitchy colors\n" \
	"\nJulia Set constants:\n" \
	"\tpress \033[1m\033[38;5;110mR\033[0m to randomize \n"\
	"\tuse \033[1m\033[38;5;110mleft_shift + scroll\033[0m " \
	"to increase or decrease\n" \
	"\tuse \033[1m\033[38;5;110mleft_ctrl + mouse \033[0m"\
	"to change constants based on relative mouse position\n");
}

void	param_error(void)
{
	puts("\n\nError - incorrect params\n\n" \
"params:\t \033[1m\033[38;5;110mmandelbrot\n" \
"\t \033[1m\033[38;5;110mtricorn\n" \
"\t julia \033[0m\033[38;5;115m<real> <imaginary>\033[0m\n\n" \
"examples:\n" \
"./fractol julia \033[38;5;115m0.285 0.01\033[0m\n" \
"./fractol julia \033[38;5;115m-0.8 0.156\n");
}
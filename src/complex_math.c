/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:53:23 by mdias             #+#    #+#             */
/*   Updated: 2024/03/01 16:01:55 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex	complex_sum(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.i = a.i + b.i;
	return (c);
}

t_complex	complex_square(t_complex z)
{
	t_complex	result;
	
	result.real = (z.real * z.real) - (z.i * z.i);
	result.i = 2 * z.real * z.i;
	
	return (result);
}

t_complex	complex_power(t_complex a, int exponent)
{
	t_complex	result;
	t_complex	temp;
	int			i;

	result.real = 1.0;
	result.i = 0.0;
	i = 0;
	while (i < exponent)
	{
		temp = result;
		result.real = temp.real * a.real - temp.i * a.i;
		result.i = temp.real * a.i + temp.i * a.real;
		i++;
	}
	return (result);
}

t_complex	complex_conjugate(t_complex a)
{
	t_complex	c;

	c.real = a.real;
	c.i = -a.i;
	return (c);
}
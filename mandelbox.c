/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:38:34 by mdias             #+#    #+#             */
/*   Updated: 2024/03/02 19:50:59 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	initialize_mandelbox(t_fractal *fractal)
{
	fractal->name = "Mandelbox";
	fractal->color = CYAN;
	fractal->type = MANDELBOX;
	fractal->iterations_def = ESCAPE_COUNT;
	fractal->box_size = 2.0; // Define the size of the box
    fractal->scale = 1.0; // Scaling factor for the box
	fractal->shift_y = -0.7;
	fractal->shift_x = 0.0;
	fractal->initial_zoom = 0.7;
	fractal->zoom = 1.0;
	fractal->xmin = -2.0 * fractal->initial_zoom;
	fractal->xmax = 2.0 * fractal->initial_zoom;
	fractal->ymin = -2.0 * fractal->initial_zoom;
	fractal->ymax = 2.0 * fractal->initial_zoom;
}

void mandelbox_pixels(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    unsigned int i;

    i = 0;
    z.real = 0.0;
    z.i = 0.0;
    c.real = ((fractal->xmax - fractal->xmin) * (x - 0)) / (WIDTH - 0)
        + fractal->xmin + fractal->shift_x;
    c.i = ((fractal->ymax - fractal->ymin) * (y - 0)) / (HEIGHT - 0)
        + fractal->ymin + fractal->shift_y;
    while (i < fractal->iterations_def)
    {
        double r = sqrt(z.real * z.real + z.i * z.i);
        if (r > 2.0) // Apply the box function if outside the unit sphere
        {
            double theta = atan2(z.i, z.real);
            double phi = acos(z.real / r);
            double scaled_r = pow(r, fractal->box_size); // Scale the magnitude
            z.real = scaled_r * sin(phi) * cos(theta);
            z.i = scaled_r * sin(phi) * sin(theta);
        }
        else
        {
            // Inside the sphere, apply the Mandelbrot iteration
            z = complex_sum(complex_square(z), c);
        }
        // Color mapping logic remains the same
        i++;
    }
}

void	mandelbox_render(t_fractal *fractal)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mandelbox_pixels(x, y, fractal);
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
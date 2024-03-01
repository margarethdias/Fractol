/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:27:44 by mdias             #+#    #+#             */
/*   Updated: 2024/03/01 17:47:40 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../.lib/MLX42/include/MLX42/MLX42.h"

# define WIDTH 800
# define HEIGHT 800
# define ESCAPE_COUNT 100

// Colors
# define BLACK		0x000000FF
# define WHITE		0xFFFFFFFF
# define MAGENTA	0xFF00FFFF
# define CYAN		0x00FFFFFF
# define YELLOW		0xFFFF00FF
# define ORANGE		0xFFA500FF
# define PURPLE		0x800080FF
# define PINK		0xFFC0CBFF
# define LIME		0x32CD32FF
# define DEEP		0xFF1493FF
# define GREEN		0x00FF00FF
# define VIOLET		0x8A2BE2FF
# define ORANGER	0xFF4500FF
# define TOMATO		0xFF6347FF
# define AQUA		0x00FFFFFF
# define TEAL		0x008080FF
# define GOLD		0xFFD700FF
# define SILVER		0xC0C0C0FF
# define GRAY		0x808080FF
# define BROWN		0xA52A2AFF

# define ERROR_MSG "Please, use the right input: \n\t\"./fractol mandelbrot\" or \n\t\"./julia <value 1> <value 2>\" \n"

/*Struct to define the complex values*/
typedef struct	s_complex
{
	double real; // cartesian x
	double i; // cartesian y
}				t_complex;

/*Fractal Struct
* MLX 
* Image
* Hooks value
*/
typedef struct s_fractal
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	char			*name;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			shift_y;
	double			shift_x;
	double			xzoom;
	double			yzoom;
	double			initial_zoom;	
	double			zoom;
	double			zoom_factor;
	double			escape_value; // hypotenuse
	int				type;
	unsigned int	iterations_def; // value tight with the image quality and rendering speed
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	color;
	unsigned int	color2;
	t_complex		c;
	
	
}				t_fractal;

typedef enum sets
{
	MANDELBROT,
	JULIA,
	TRICORN,
}	t_sets;

// * Initialize Fractol *
void	render_fractal_type(t_fractal *fractal);
void	fractal_init(t_fractal *fractal, int type, double c_x, double c_y);
void	render_fractal_type(t_fractal *fractal);

// * Mandelbroat *
void	initialize_mandelbroat(t_fractal *fractal);
void	mandelbroat_pixels(int x, int y, t_fractal *fractal);
void	mandelbrot_render(t_fractal *fractal);

// * Julia *
void	initialize_julia(t_fractal *fractal, double c_x, double c_y);
void	julia_pixels(int x, int y, t_fractal *fractal);
void	random_julia(t_fractal *fractal_ptr);
void	julia_render(t_fractal *fractal);

// * Tricorn *
void	initialize_tricorn(t_fractal *fractal);
void	tricorn_pixels(int x, int y, t_fractal *fractal);
void	tricorn_render(t_fractal *fractal);

// *HOOKS*
//static void keyboard_arrows(t_fractal *fractal);
void	keyhook(void *param);

// *Math*
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	complex_sum(t_complex z1, t_complex z2);
t_complex	complex_square(t_complex z);
t_complex	complex_power(t_complex a, int exponent);
t_complex	complex_conjugate(t_complex a);

// *Strings Utils*
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
double	ft_atod(char *str);

// *Color Iterations
void			change_color(t_fractal *fractal);
unsigned int	reduce_color_intensity(t_fractal *fractal);
unsigned int	color_iteration_mapping(int iter, t_fractal *fractal);

// * Messages *
void	param_error(void);
void	controls_msg(void);
void	error_msg(void);

// /**
//  * Main MLX handle, carries important data in regards to the program.
//  * @param window The window itself.
//  * @param context Abstracted opengl data.
//  * @param width The width of the window.
//  * @param height The height of the window.
//  * @param delta_time The time difference between the previous frame and the current frame.
//  */
// typedef struct mlx
// {
// 	void*		window;
// 	void*		context;
// 	int32_t		width;
// 	int32_t		height;
// 	double		delta_time;
// }	mlx_t;

#endif
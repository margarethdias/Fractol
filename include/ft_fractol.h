/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:27:44 by mdias             #+#    #+#             */
/*   Updated: 2024/01/19 20:06:46 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../.lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define WIDTH 512
# define HEIGHT 512

/*Image Struct
- Pixels buffer
- mlx values */



/*Fractal Struct
* MLX 
* Image
* Hooks value
*/
typedef struct s_fractal
{
	
}

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
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
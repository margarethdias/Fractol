/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdias <mdias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:31:13 by mdias             #+#    #+#             */
/*   Updated: 2024/01/18 19:29:21 by mdias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

#define SQUARE_SIZE 45 // Assuming each square is 45x45 pixels
#define BOARD_SIZE 8   // 8x8 chessboard

int main()
{
    int x, y, i, j;
    uint32_t color;

    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    mlx_image_t *win = mlx_new_image(mlx, WIDTH, HEIGHT);
    mlx_image_to_window(mlx, win, 0, 0);

    for (i = 0; i < BOARD_SIZE; ++i)
    {
        for (j = 0; j < BOARD_SIZE; ++j)
        {
            // Determine the color of the square
            if ((i + j) % 2 == 0)
                color = 0x6B238EFF;  // White
            else
                color = 0x000000FF;  // Black

            // Calculate the top-left corner of the square
            x = j * SQUARE_SIZE;
            y = i * SQUARE_SIZE;

            // Draw the square
            for (int square_x = x; square_x < x + SQUARE_SIZE; ++square_x)
            {
                for (int square_y = y; square_y < y + SQUARE_SIZE; ++square_y)
                {
                    mlx_put_pixel(win, square_x, square_y, color);
                }
            }
        }
    }

    mlx_loop(mlx);
}

// typedef struct s_rect
// {
//     int x;
//     int y;
//     int size;
//     int color;
// } t_rect;

// void render_square(mlx_image_t *win, t_rect rect)
// {
//     int i;
//     int j;

//     i = rect.y;
//     while (i < rect.y + rect.size)
//     {
//         j = rect.x;
//         while (j < rect.x + rect.size)
//         {
//             mlx_put_pixel(win, j++, i, rect.color);
//         }
//         ++i;
//     }
// }

// int main()
// {
//     mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
//     mlx_image_t *win = mlx_new_image(mlx, 640, 360);
//     mlx_image_to_window(mlx, win, 100, 150);
    
//     t_rect rect = {2, 3, 50, 0x6B238EFF}; // Define a square with top-left corner at (2,3), size 100x100, and color
//     render_square(win, rect);

//     mlx_loop(mlx);
// }

// int main()
// {
// 	int x;
// 	int y;
// 	x = 2;
// 	y = 3;
	
// 	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
//     mlx_image_t *win = mlx_new_image(mlx, 640, 360);
// 	mlx_image_to_window(mlx, win, 150, 150);
	
// 	while (x < 100)
//     	mlx_put_pixel(win, x++, 30, 0x6B238EFF);

//     mlx_loop(mlx);
// }



// static mlx_image_t* image;

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	for (int32_t i = 0; i < image->width; ++i)
// 	{
// 		for (int32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// int32_t main(int32_t argc, const chputar* argv[])
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

// // Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// // Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// int32_t	main(void)
// {

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		ft_error();

// 	/* Do stuff */

// 	// Create and display the image.
// 	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_error();

// 	// Even after the image is being displayed, we can still modify the buffer.
// 	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

// 	// Register a hook and pass mlx as an optional param.
// 	// NOTE: Do this before calling mlx_loop!
// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
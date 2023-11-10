/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/04 12:59:29 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"myfdf.h"

/// @brief 			Draws a hand on the clock : bresenham algorithm
/// @param mlx		MLX pointer
/// @param window	MLX window pointer
/// @param img		hand data (position, size, color)
void	mlx_minutes_hand_b(void *mlx, void *window, t_img_data *img)
{
	int				i;
	int				j;
	double static	alfa;

	alfa = 6.28318530718;
	while (alfa > 0)
	{
		i = my_round(cos(alfa - 45 * 0.10471975512) * (img->radius - 40));
		j = my_round(sin(alfa - 45 * 0.10471975512) * (img->radius - 40));
		mlx_line_b(img, img->x, img->y, (int)(img->x + i), (int)(img->y - j),
			img->color);
		mlx_put_image_to_window(mlx, window, img->img_ptr, 0, 0);

		alfa -= 0.10471975512;
	}
}

/// @brief			Draws a hand on the clock : my algorithm
/// @param mlx		MLX pointer
/// @param window	MLX window pointer
/// @param img		hand data (position, size, color)
void	mlx_secs_hand(void *mlx, void *window, t_img_data *img)
{
	int		i;
	int		j;
	double	alfa;

	alfa = 6.28318530718;
	while (alfa > 0)
	{
		i = my_round(cos(alfa - 45 * 0.10471975512) * (img->radius - 20));
		j = my_round(sin(alfa - 45 * 0.10471975512) * (img->radius - 20));
		mlx_line(img, img->x, img->y, (int)(img->x + i), (int)(img->y - j),
			img->color);
		mlx_put_image_to_window(mlx, window, img->img_ptr, 0, 0);
		sleep(1);
		mlx_line(img, img->x, img->y, (int)(img->x + i), (int)(img->y - j),
			0x0000FF);
		mlx_put_image_to_window(mlx, window, img->img_ptr, 0, 0);
		alfa -= 0.10471975512;
	}
}

/// @brief 			Draws a hand on the clock : bresenham algorithm
/// @param mlx		MLX pointer
/// @param window	MLX window pointer
/// @param img		hand data (position, size, color)
void	mlx_secs_hand_b(void *mlx, void *window, t_img_data *img)
{
	int		i;
	int		j;
	double	alfa;

	alfa = 6.28318530718;
	while (alfa > 0)
	{
		i = my_round(cos(alfa - 45 * 0.10471975512) * (img->radius - 20));
		j = my_round(sin(alfa - 45 * 0.10471975512) * (img->radius - 20));
		mlx_line_b(img, img->x, img->y, (int)(img->x + i), (int)(img->y - j),
			img->color);
		mlx_put_image_to_window(mlx, window, img->img_ptr, 0, 0);
		sleep(1);
		mlx_line_b(img, img->x, img->y, (int)(img->x + i), (int)(img->y - j),
			0x0000FF);
		mlx_put_image_to_window(mlx, window, img->img_ptr, 0, 0);
		alfa -= 0.10471975512;
	}
}

/// @brief			Draws a clock
/// @param mlx		MLX pointer
/// @param mlx_win	MLX window pointer
/// @param img		clock data (position, size, color)
void	mlx_clock(void *mlx, void *mlx_win, t_img_data *img)
{
	int	frame;

	frame = 0;
	img->x = (FHD_SX / 4) * 1;
	while (frame < 16)
		mlx_circle(img, img->x, img->y, img->radius + frame++, img->color);
	mlx_put_image_to_window(mlx, mlx_win, img->img_ptr, 0, 0);
	mlx_secs_hand(mlx, mlx_win, img);

	frame = 0;
	img->x = (FHD_SX / 4) * 3;
	while (frame < 16)
		mlx_circle_g(img, img->x, img->y, img->radius + frame++, img->color);
	mlx_put_image_to_window(mlx, mlx_win, img->img_ptr, 0, 0);
	mlx_secs_hand_b(mlx, mlx_win, img);
	return ;
}


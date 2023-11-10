/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_squares.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/03 17:39:25 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"

void	mlx_square(t_win_data *img, t_mlx_square *sq)
{
	t_mlx_pixel	pixel;

	pixel.color = sq->color;
	pixel.x = sq->x;
	while ((pixel.x - sq->x) < sq->size)
	{
		pixel.y = sq->y;
		while ((pixel.y - sq->y) < sq->size)
		{
			mlx_pixel_s(img, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

void	mlx_square_tester(t_win_data *win_data)
{
	t_mlx_square	sq;

	printf(" => Centered Fill Square ...");
	sq.size = IM1_SX;
	sq.x = (F_SX / 2) - sq.size / 2;
	sq.y = F_SY / 6 + sq.size / 2;
	sq.color = YELLOWGREEN;
	mlx_square(win_data, &sq);
	mlx_put_image_to_window(win_data->mlx, win_data->win,
		win_data->img_ptr, 0, 0);
	printf(" OK!!\n");
	sleep(3);
	return ;
}


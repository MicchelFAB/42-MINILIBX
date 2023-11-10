/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_circles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/19 13:38:30 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"

void	mlx_circle_(t_win_data *img, t_mlx_circle *circle)
{
	int		i;
	int		j;
	double	alfa;

	alfa = 0;
	while (alfa < PI2)
	{
		i = my_round(cos(alfa) * circle->radius);
		j = my_round(sin(alfa) * circle->radius);
		mlx_pixel_s(img, &((t_mlx_pixel)
			{circle->x + i, circle->y - j, circle->color}));
		alfa += DEG2RAD_1 / 10;
	}
	return ;
}

void	mlx_circle_tester(t_win_data *win)
{
	t_mlx_circle	circle;

	circle.color = BLACK;
	circle.radius = 10;
	printf(" => Circunferences ...");
	circle.x = IM1_SX;
	circle.y = IM1_SY;
	mlx_circle_(win, &circle);
	circle.y = F_SY - IM1_SY;
	mlx_circle_(win, &circle);
	circle.x = F_SX - IM1_SX;
	mlx_circle_(win, &circle);
	circle.y = IM1_SY;
	mlx_circle_(win, &circle);
	mlx_put_image_to_window(win->mlx, win->win, win->img_ptr, 0, 0);
	printf(" OK!!\n");
	return ;
}


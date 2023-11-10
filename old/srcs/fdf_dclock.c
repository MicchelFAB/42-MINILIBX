/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dclock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/09 22:50:05 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"

void	mlx_clock_secs_hand(t_win_data *img, t_mlx_circle *c)
{
	t_mlx_line	l;
	double		alfa;

	alfa = PI2;
	l.x0 = c->x;
	l.y0 = c->y;
	while (alfa > 0)
	{
		l.xn = (l.x0 + my_round(cos(alfa + DEG2RAD_90)
					* (c->radius - 20)));
		l.yn = (l.y0 - my_round(sin(alfa + DEG2RAD_90)
					* (c->radius - 20)));
		l.color = c->color;
		mlx_line(img, &l);
		mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
		usleep(1000 * 100);
		mlx_line_c(img, &l);
		alfa -= SECS_CLK_HAND;
	}
	mlx_line(img, &((t_mlx_line)
		{l.x0, l.y0, l.x0, l.y0 - c->radius + 20, c->color,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	return ;
}

void	clock_frame(t_win_data *img, int thick, t_mlx_circle *circle)
{
	while (thick-- > 0)
	{
		mlx_circle_(img, circle);
		circle->radius++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	return ;
}

void	mlx_clock(t_win_data *img)
{
	printf(" => Clock with circunference frame ...\n");
	clock_frame(img, 16, &((t_mlx_circle)
		{(F_SX / 4) * 3, F_SY / 2, 120, CYAN}));
	mlx_clock_secs_hand(img, &((t_mlx_circle)
		{(F_SX / 4) * 3, F_SY / 2, 120, CYAN}));
	printf(" OK!!\n");
	return ;
}

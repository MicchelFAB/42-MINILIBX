/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drectangles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/09 22:50:05 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"

void	mlx_rectangle_corners(t_win_data *img, t_mlx_rect *rt)
{
	t_mlx_pixel	pixel;

	pixel.color = rt->color;
	pixel.x = rt->x;
	pixel.y = rt->y;
	mlx_pixel_s(img, &pixel);
	pixel.x = rt->x + rt->w;
	pixel.y = rt->y;
	mlx_pixel_s(img, &pixel);
	pixel.x = rt->x;
	pixel.y = rt->y + rt->h;
	mlx_pixel_s(img, &pixel);
	pixel.x = rt->x + rt->w;
	pixel.y = rt->y + rt->h;
	mlx_pixel_s(img, &pixel);
	return ;
}

void	mlx_rectangle_sides(t_win_data *img, t_mlx_rect *rt)
{
	mlx_line(img, &((t_mlx_line)
		{rt->x, rt->y, rt->x + rt->w, rt->y, rt->color,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line)
		{rt->x, rt->y, rt->x, rt->y + rt->h, rt->color,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line)
		{rt->x + rt->w, rt->y + rt->h, rt->x + rt->w, rt->y, rt->color,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line)
		{rt->x + rt->w, rt->y + rt->h, rt->x, rt->y + rt->h, rt->color,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	return ;
}

void	mlx_rectangle_face(t_win_data *img, t_mlx_rect *rt)
{
	t_mlx_pixel	pixel;

	pixel.color = rt->color;
	pixel.x = rt->x;
	while ((pixel.x - rt->x) < rt->w)
	{
		pixel.y = rt->y;
		while ((pixel.y - rt->y) < rt->h)
		{
			mlx_pixel_s(img, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

void	mlx_menu_border(t_win_data *img, t_mlx_rect *rt)
{
	t_mlx_pixel	pixel;

	pixel.color = rt->color;
	pixel.x = rt->x;
	while ((pixel.x - rt->x) < rt->w)
	{
		pixel.y = rt->y;
		while ((pixel.y - rt->y) < rt->h)
		{
			mlx_pixel_s(img, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

void	mlx_rectangle_menu(t_win_data *img)
{
	t_mlx_rect	rt;
	int			border;

	border = 4;
	rt = (t_mlx_rect){border, border, (D_SX / 8) - 2 * border, D_SY - 2 * border, GRAY};
	mlx_rectangle_face(img, &rt);

	rt = (t_mlx_rect){0, 0, (D_SX / 8), border, DARKGRAY};
	mlx_menu_border(img, &rt);
	rt = (t_mlx_rect){0, 0, border, D_SY, DARKGRAY};
	mlx_menu_border(img, &rt);
	rt = (t_mlx_rect){0, D_SY - border, (D_SX / 8), border, LIGHTGRAY};
	mlx_menu_border(img, &rt);
	rt = (t_mlx_rect){(D_SX / 8) - border, 0, border, D_SY, SILVER};
	mlx_menu_border(img, &rt);
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);

}

void	mlx_rectangle_tester(t_win_data *win_data)
{
	t_mlx_rect	rt;

	printf(" => Rectangle ...");
	printf(" => sides ...");

	rt.w = IM1_SX;
	rt.h = IM1_SY;
	rt.x = IM1_SX;
	rt.y = IM1_SY;
	rt.color = RED;
	mlx_rectangle_sides(win_data, &rt);
	mlx_put_image_to_window(win_data->mlx, win_data->win,
		win_data->img_ptr, 0, 0);

	printf(" => face ...");
	rt.x = IM1_SX * 3;
	rt.y = IM1_SY;
	rt.color = BLUEVIOLET;
	mlx_rectangle_face(win_data, &rt);
	mlx_put_image_to_window(win_data->mlx, win_data->win,
		win_data->img_ptr, 0, 0);

	printf(" => corners ...");
	rt.x = IM1_SX * 5;
	rt.y = IM1_SY;
	rt.color = YELLOW;
	mlx_rectangle_corners(win_data, &rt);
	mlx_put_image_to_window(win_data->mlx, win_data->win,
		win_data->img_ptr, 0, 0);

	printf(" OK!!\n");
	return ;
}

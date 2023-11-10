/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_color_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:38:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/29 15:40:23 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

//int	color_map_1(void *win, int w, int h)
int	color_map_1(t_window *win)
{
	int	x;
	int	y;
	int	color;

	x = win->w;
	while (x--)
	{
		y = win->h;
		while (y--)
		{
			color = (x * BM) / win->w + ((((win->w - x) * BM) / win->w) << 16)
				+ (((y * BM) / win->h) << 8);
			mlx_pixel_put(win->mlx, win->win, x, y, color);
		}
	}
	return (SUCCESS);
}

int	color_map_2(t_window *win)
{
	int				x;
	int				y;
	int				dec;
	int				c2;
	unsigned char	*ptr;

	win->opp = win->bpp / 8;
	printf("(opp : %d) ", win->opp);
	y = win->img_h;
	while (y--)
	{
		ptr = win->data + y * win->sl;
		x = win->img_w;
		while (x--)
		{
			if (win->type == 2)
				win->color = (y * BM) / win->img_w
					+ ((((win->img_w - x) * BM) / win->img_w) << 16)
					+ (((y * BM) / win->img_h) << 8);
			else
				win->color = (x * BM) / win->img_w
					+ ((((win->img_w - x) * BM) / win->img_w) << 16)
					+ (((y * BM) / win->img_h) << 8);
			c2 = mlx_get_color_value(win->mlx, win->color);
			dec = win->opp;
			while (dec--)
			{
				if (win->endian == win->l_endian)
				{
					if (win->endian)
						*(ptr + x * win->opp + dec)
							= ((unsigned char *)(&c2))[4 - win->opp + dec];
					else
						*(ptr + x * win->opp + dec)
							= ((unsigned char *)(&c2))[dec];
				}
				else
				{
					if (win->endian)
						*(ptr + x * win->opp + dec)
							= ((unsigned char *)(&c2))[win->opp - 1 - dec];
					else
						*(ptr + x * win->opp + dec)
							= ((unsigned char *)(&c2))[3 - dec];
				}
			}
		}
	}
	return (SUCCESS);
}

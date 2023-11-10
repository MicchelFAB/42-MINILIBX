/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:01:59 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/21 20:06:08 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx.h"
#include	"mlx_int.h"
#include	"mlx_test.h"

int	fill_win_grade(void *fmlx, void *win, int w, int h)
{
	int	x;
	int	y;
	int	color;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
		mlx_pixel_put(fmlx, win, x, y, color);
		}
	}
}
int	fill_win_color(void *fmlx, void *win, int w, int h, int color)
{
	int	x;
	int	y;

	x = w;
	while (x--)
	{
		y = h;
		while (y--)
			mlx_pixel_put(fmlx, win, x, y, color);
	}
}

int	fill_img_grade(void *fmlx, unsigned char *data, int bpp, int sl, int w, int h, int endian, int type)
{
	int	x;
	int	y;
	int	opp;
	int	dec;
	int	color;
	int	color2;
	unsigned char *ptr;

	opp = bpp/8;
	//printf("(opp : %d) ", opp);
	y = h;
	while (y--)
	{
		ptr = data + y * sl;
		x = w;
		while (x--)
		{
			if (type == 2)
				color = (y * 255) / w
					+ ((((w - x) * 255) / w) << 16)
					+ (((y * 255) / h) << 8);
			else
				color = (x * 255) / w
					+ ((((w - x) * 255) / w) << 16) + (((y * 255) / h) <<8);
			color2 = mlx_get_color_value(fmlx, color);
			dec = opp;
			while (dec--)
			{
				if (endian == l_endian)
				{
					if (endian)
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[4-opp+dec];
					else
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[dec];
				}
				else
				{
					if (endian)
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[opp-1-dec];
					else
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[3-dec];
				}
			}
		}
	}

}

int	fill_img_grade_s(void *fmlx, unsigned char *data, int bpp, int sl, int w, int h, int endian, int type)
{
	int	x;
	int	y;
	int	opp;
	int	dec;
	int	color;
	int	color2;
	unsigned char *ptr;

	opp = bpp/8;
	//printf("(opp : %d) ", opp);
	y = h;
	while (y--)
	{
		ptr = data + y * sl;
		x = w;
		while (x--)
		{
			if (type == 2)
				color = (y*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
			else
				color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
			color2 = mlx_get_color_value(fmlx, color);
			dec = opp;
			while (dec--)
			{
				if (endian == l_endian)
				{
					if (endian)
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[4-opp+dec];
					else
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[dec];
				}
				else
				{
					if (endian)
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[opp-1-dec];
					else
						*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[3-dec];
				}
			}
		}
		printf("(c1 <= %x ? %x => c2) \n", color, color2);

	}

}
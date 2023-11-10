/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/20 16:02:28 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"

void	mlx_pixel_s(t_win_data *img, t_mlx_pixel *pixel)
{
	char	*dst;

	dst = img->addr + (pixel->y * img->ll
			+ pixel->x * (img->bpp / 8));
	*(unsigned int *)dst = pixel->color;
}

void	mlx_pixel_tester(t_win_data *img)
{
	t_mlx_pixel	pixel;

	printf(" => All Pixel ...");
	pixel.x = 0;
	while (pixel.x < F_SX)
	{
		pixel.y = 0;
		while (pixel.y < F_SY)
		{
			pixel.color = (((pixel.x * 255) / F_SX) << 8)
				+ (((F_SY - pixel.y) * 255) / F_SY)
				+ (((pixel.y * 255) / F_SY) << 16);
			mlx_pixel_s(img, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
	//mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	printf(" OK!!\n");
	return ;
}

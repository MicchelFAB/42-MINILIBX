/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_circles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/04 13:21:52 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"myfdf.h"

void	mlx_circle(t_img_data *img, int x, int y, int radius, int color)
{
	int		i;
	int		j;
	double	alfa;

	alfa = 0;
	while (alfa < 6.28318530718)
	{
		i = cos(alfa) * radius;
		j = sin(alfa) * radius;
		mlx_pixel(img, x + i, y - j, color);
		alfa += 0.001745329252;
	}
}

void	mlx_circle_g(t_img_data *img, int x, int y, int radius, int color)
{
	int		i;
	int		j;
	double	alfa;

	alfa = 0;
	while (alfa < 6.28318530718)
	{
		i = cos(alfa) * radius;
		j = sin(alfa) * radius;
		mlx_pixel(img, x + i, y - j, 0x00FF00 * (int)(alfa * 40));
		alfa += 0.001745329252;
	}
}

//void	mlx_secs_hand(void *mlx, void *window, t_img_data *img, int x, int y, int radius, int color)
void	mlx_secs_hand(void *mlx, void *window, t_img_data *img)
{
	int		i;
	int		j;
	double	alfa;

	alfa = 6.28318530718;
	while (alfa > 0)
	{
		i = my_round(cos(alfa + 1.57079632678) * (img->radius - 20));
		j = my_round(sin(alfa + 1.57079632678) * (img->radius - 20));
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
//void	mlx_secs_hand(void *mlx, void *window, t_img_data *img, int x, int y, int radius, int color)
void	mlx_secs_hand_b(void *mlx, void *window, t_img_data *img)
{
	int		i;
	int		j;
	double	alfa;

	alfa = 6.28318530718;
	while (alfa > 0)
	{
		i = my_round(cos(alfa + 1.57079632678) * (img->radius - 20));
		j = my_round(sin(alfa + 1.57079632678) * (img->radius - 20));
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
void	mlx_clock(void *mlx, void *mlx_win, t_img_data *img)
{
	int	frame;
	clock_t t;
	frame = 0;
	img->x = (FHD_SX / 4) * 1;
	while (frame < 16)
		mlx_circle(img, img->x, img->y, img->radius + frame++, img->color);
	mlx_put_image_to_window(mlx, mlx_win, img->img_ptr, 0, 0);

	t = clock();
	mlx_secs_hand(mlx, mlx_win, img);
	t = clock() - t;
	printf("line() took %f cloks to execute \n", (double)t);

	frame = 0;
	img->x = (FHD_SX / 4) * 3;
	while (frame < 16)
		mlx_circle_g(img, img->x, img->y, img->radius + frame++, img->color);
	mlx_put_image_to_window(mlx, mlx_win, img->img_ptr, 0, 0);

	t = clock();
	mlx_secs_hand_b(mlx, mlx_win, img);
	t = clock() - t;
	printf("line_b() took %f clocks to execute \n", (double)t);

	return ;
}

void	mlx_line_tester(void *mlx, void *win, t_img_data *img)
{
	//mlx_line(img, 70, 70, 170, 70, 0x00FF00);
	//mlx_line(img, 70, 70, 70, 170, 0xFF0000);
	//mlx_line(img, 70, 70, 170, 170, 0x00FFFF);
	mlx_line(img, 100, 100, 315, 50, 0xFFFFFF);
	mlx_put_image_to_window(mlx, win, img->img_ptr, 0, 0);

	//mlx_line(img, 180, 180, 180, 80, 0x00FF00);
	//mlx_line(img, 180, 180, 80, 180, 0xFF0000);
	//mlx_line_b(img, 180, 180, 100, 100, 0x0000FF);
	mlx_put_image_to_window(mlx, win, img->img_ptr, 0, 0);

	// mlx_line_b(img, 270, 270, 370, 270, 0x00FF00);
	// mlx_line_b(img, 270, 270, 270, 370, 0xFF0000);
	// mlx_line_b(img, 270, 270, 370, 370, 0x00FFFF);
	mlx_line_b(img, 140, 100, 355, 50, 0xFFFFFF);
	mlx_put_image_to_window(mlx, win, img->img_ptr, 0, 0);

	// mlx_line_b(img, 380, 380, 380, 280, 0x00FF00);
	// mlx_line_b(img, 380, 380, 280, 380, 0xFF0000);
	// mlx_line_b(img, 380, 380, 300, 300, 0x0000FF);
	// mlx_put_image_to_window(mlx, win, img->img_ptr, 0, 0);
	return ;
}
int	main(void)
{
	void		*mlx;
	void		*mlx_win_fhd;
	void		*mlx_win_shd;
	t_img_data	img;
	int			sleep_time;



	printf("new version 3\n");

	printf(" => Connection ...");
	mlx = mlx_init();
	if (!mlx)
	{
		printf(" !! KO !! mlx connection failed\n");
		exit(1);
	}
	printf(" OK!! Connection active\n");

	printf(" => Window1 %dx%d \"Hello World! FHD\" ...", FHD_SX, FHD_SY);
	mlx_win_fhd = mlx_new_window(mlx, FHD_SX, FHD_SY, "Hello World! FHD");
	if (!(mlx_win_fhd))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf(" OK!! Window ready\n");

	printf(" => Image prepare ...");
	img.img_ptr = mlx_new_image(mlx, FHD_SX, FHD_SY);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	printf(" => Image info: bpp = %d, line length =%d, endian = %d\n",
		img.bits_per_pixel, img.line_length, img.endian);

	printf(" => Pixel ...");
	img.width = 1;
	img.height = 1;
	img.x = FHD_SX / 10 * 1;
	img.y = FHD_SY / 10 * 9;
	img.color = GOLD;
	mlx_square(&img);
	mlx_put_image_to_window(mlx, mlx_win_fhd, img.img_ptr, 0, 0);

	printf(" => Centered Fill Square ...");
	img.width = IM1_SX;
	img.height = IM1_SY;
	img.x = FHD_SX / 8 - img.width / 2;
	img.y = FHD_SY / 6 + img.height / 2;
	img.color = CYAN;
	mlx_square(&img);
	mlx_put_image_to_window(mlx, mlx_win_fhd, img.img_ptr, 0, 0);
	printf(" OK!!\n");

	mlx_line_tester(mlx, mlx_win_fhd, &img);

	printf(" => Circunferences ...");
	img.x = FHD_SX / 10 * 1;
	img.y = FHD_SY / 10 * 9;
	img.radius = 10;
	img.color = KHAKI;
	mlx_circle(&img, img.x, img.y, img.radius, img.color);
	printf(" OK!!\n");

	//mlx_circle(mlx, mlx_win_fhd, &img);

	printf(" => Clock with circunference frame ...\n");
	img.x = FHD_SX / 2;
	img.y = FHD_SY / 2;
	img.radius = 120;
	img.color = ORANGERED;
	mlx_clock(mlx, mlx_win_fhd, &img);
	printf(" OK!!\n");

	mlx_loop(mlx);
}
/* more examples
	printf(" => Window1 %dx%d \"Hello World! SHD\" ...", SHD_SX, SHD_SY);
	mlx_win_shd = mlx_new_window(mlx, SHD_SX, SHD_SY, "Hello World! SHD");
	if (!(mlx_win_shd))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf(" OK!! Window ready\n");
*/
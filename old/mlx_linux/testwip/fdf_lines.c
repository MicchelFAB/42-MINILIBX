/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/15 17:29:51 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"myfdf.h"

void	mlx_square(t_img_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->width)
	{
		j = 0;
		while (j < img->height)
		{
			mlx_pixel(img, img->x + i, img->y + j, img->color);
			j++;
		}
		i++;
	}
}

void	mlx_rectangle(t_img_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->width)
	{
		j = 0;
		while (j < img->height)
		{
			mlx_pixel(img, img->x + i, img->y + j, img->color);
			j++;
		}
		i++;
	}
}

int	abs_i(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
void	ft_abs(void *n)
{
	if (*n < 0)
		*n = *n * (-1);
	return ;
}
double	abs_d(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
int max_i(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
int min_i(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char sign_d(double n)
{
	if (n < 0)
		return (-1);
	return (1);
}
int	my_round(double n)
{
	if ((sign_d(n) * (n - (int)n)) >= 0.5)
		return ((int)n + sign_d(n));
	return ((int)n);
}
int	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

void	mlx_line(t_img_data *img, int x1, int y1, int x2, int y2, int color)
{
	double	x;
	double	y;
	double	d;
	double	id;

	if (x1 == x2)
	{
		if (y1 < y2)
			while (y1 <= y2)
				mlx_pixel(img, x1, y1++, color);
		else
			while (y2 <= y1)
				mlx_pixel(img, x1, y2++, color);
		return ;
	}

	if (y1 == y2)
	{
		if (x1 < x2)
			while (x1 < x2)
				mlx_pixel(img, x1++, y1, color);
		else
			while (x2 < x1)

				mlx_pixel(img, x2++, y1, color);
		return ;
	}

	d = abs_d((double)(y2 - y1) / (double)(x2 - x1));
	id = 1 / d;
	x = x1;
	y = y1;

	while (x != x2 && y != y2)
	{
		mlx_pixel(img, (unsigned int)x, (unsigned int)y, color);
		if (d < 1)
		{
			if (x1 < x2)
				x++;
			else
				x--;
			if (y1 < y2)
				y += d;
			else
				y -= d;
		}
		else
		{
			if (x1 < x2)
				x += id;
			else
				x -= id;
			if (y1 < y2)
				y++;
			else
				y--;
		}
	}

}
void	mlx_line_b(t_img_data *img, int x0, int y0, int xn, int yn, int color)
{
	int	xk;
	int	yk;
	int	ek;
	int	dx;
	int	dy;
	int		sdx;
	int		sdy;
	int		swap;
	int		k;

	k = 1;
	swap = 0;
	xk = x0;
	yk = y0;
	dx = abs_i(xn - x0);
	dy = abs_i(yn - y0);
	sdx = sign_d(xn - x0);
	sdy = sign_d(yn - y0);

	if (dy > dx)
		swap = ft_swap(&dx, &dy);
	ek = 2 * dy - dx;
	mlx_pixel(img, xk, yk, color);

	//printf("%sx0(%d),xn(%d) | y0(%d), yn(%d)%s\n",
	//	SYLW, x0, xn, y0, yn, SWHT);
	//printf("%sdx = %d, dy = %d, ek = %d%s\n", SGRN, dx, dy, ek, SWHT);
	while (k <= dx)
	{
		k++;
		mlx_pixel(img, xk, yk, color);
		if (ek < 0)
		{
			if (swap)
				yk += sdy;
			else
				xk += sdx;
			ek = ek + 2 * dy;
			//printf("%sek < 0 ** xk = %d, yk = %d, ek = %d%s\n",
			//	SCYN, xk, yk, ek, SWHT);
		}
		else
		{
			yk += sdy;
			xk += sdx;
			ek = ek + 2 * dy - 2 * dx;
			//printf("%sek > 0 ** xk = %d, yk = %d, ek = %d%s\n",
			//	SBLU, xk, yk, ek, SWHT);
		}
	}
}


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
		i = my_round(cos(alfa - 45 * 0.10471975512) * (img->radius - 20));
		j = my_round(sin(alfa - 45 * 0.10471975512) * (img->radius - 20));
		mlx_line(img, img->x, img->y, (int)(img->x + i), (int)(img->y - j),
			img->color);
		mlx_put_image_to_window(mlx, window, img->img_ptr, 0, 0);
		//sleep(1);
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
		i = my_round(cos(alfa - 45 * 0.10471975512) * (img->radius - 20));
		j = my_round(sin(alfa - 45 * 0.10471975512) * (img->radius - 20));
		mlx_line_b(img, img->x, img->y, (int)(img->x + i), (int)(img->y - j),
			img->color);
		mlx_put_image_to_window(mlx, window, img->img_ptr, 0, 0);
		//sleep(1);
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
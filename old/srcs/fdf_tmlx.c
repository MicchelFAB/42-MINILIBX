/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tmlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/06 17:34:57 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"

void	mlx_test(t_win_data *img)
{
	mlx_pixel_tester(img);
	sleep(SLEEP);
	mlx_line_tester(img);
	sleep(SLEEP);
	mlx_square_tester(img);
	sleep(SLEEP);
	mlx_rectangle_tester(img);
	sleep(SLEEP);
	mlx_circle_tester(img);
	sleep(SLEEP);
	mlx_clock(img);
	return ;
}

// t_mesh	create_cube(int x, int y, int z, int size)
// {
// 	t_mesh	*cube;

// 	cube = (t_mesh *)malloc(sizeof(t_mesh));
// 	if (!cube)
// 	{
// 		printf(" !! KO !!\n");
// 		exit(1);
// 	}
// 	cube->tris->p[0] = (t_v3d){0, 0, 0};
// 	cube->tris->p[1] = (t_v3d){0, 1, 0};
// 	cube->tris->p[2] = (t_v3d){1, 1, 0};

// 	cube->tris = {
// 	//SOUTH
// 		{0.0, 0.0, 0.0,  0.0, 1.0, 0.0,  1.0, 1.0, 0.0}
// 		{0.0, 0.0, 0.0,  1.0, 1.0, 0.0,  1.0, 0.0, 0.0}
// 	//EAST
// 		{1.0, 0.0, 0.0,  1.0, 1.0, 0.0,  1.0, 1.0, 1.0}
// 		{1.0, 0.0, 0.0,  1.0, 1.0, 1.0,  1.0, 0.0, 1.0}
// 	//NORTH
// 		{1.0, 0.0, 1.0,  1.0, 1.0, 1.0,  0.0, 1.0, 1.0}
// 		{1.0, 0.0, 1.0,  0.0, 1.0, 1.0,  0.0, 0.0, 1.0}
// 	//WEST
// 		{0.0, 0.0 1.0, 0.0, 1.0, 1.0,  0.0, 1.0, 0.0}
// 		{0.0, 0.0 1.0,  0.0, 1.0, 0.0,  0.0, 0.0, 0.0}
// 	//TOP
// 		{0.0, 1.0, 0.0,  0.0, 1.0, 1.0,  1.0, 1.0, 1.0}
// 		{0.0, 1.0, 0.0,  1.0, 1.0, 1.0,  1.0, 1.0, 0.0}
// 	//BOTTOM
// 		{0.0, 0.0, 1.0,  0.0, 0.0, 0.0,  1.0, 0.0, 0.0}
// 		{0.0, 0.0, 1.0,  1.0, 0.0, 0.0,  1.0, 0.0, 1.0}
// 	}

// 	cube->x = x;
// 	cube->y = y;
// 	cube->z = z;
// 	cube->size = size;
// 	return (cube);
// }

void	mlx_get_gray(t_win_data *img)
{
	int shape_w = 200;
	int shape_h = 50;
	int shape_x = 400;
	int shape_y = 50;
	int i =1;
	//mlx_string_put(mlx,win1,5,WIN1_SY/2,0xFF99FF,"String output");
	//mlx_string_put(mlx,win1,15,WIN1_SY/2+20,0x00FFFF,"MinilibX test");
	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i, shape_w, shape_h, GAINSBORO});
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	mlx_string_put(img->mlx, img->win, shape_x + 10, shape_y * i++ + shape_h / 2, RED, "GAINSBORO");
	sleep(5);
	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i, shape_w, shape_h, LIGHTGRAY});
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, shape_x, shape_y * i);
	mlx_string_put(img->mlx, img->win, shape_x + 10, shape_y * i++ + shape_h / 2, RED, "LIGHTGRAY");
	sleep(5);

	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i++, shape_w, shape_h, SILVER});
	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i++, shape_w, shape_h, DARKGRAY});
	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i++, shape_w, shape_h, GRAY});
	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i++, shape_w, shape_h, DIMGRAY});
	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i++, shape_w, shape_h, ALMOSTBLACK});
	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i++, shape_w, shape_h, LIGHTSLATEGRAY});
	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i++, shape_w, shape_h, SLATEGRAY});
	mlx_rectangle_face(img, &(t_mlx_rect){shape_x, shape_y * i++, shape_w, shape_h, DARKSLATEGRAY});
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
}

/// @brief		mlx_tester will test and pratice the basic functions
/// 			available in the mlx library and additional functions created
/// 			for this project: pixels, lines, circles, squares/rectangles
///				This function might be used as "main" for the sole purpose of
/// 			the	mentioned tests, without any further requirement
/// @param		void
/// @return		SUCCESS or ERROR
int	mlx_tester(void)
{
	t_win_data	img;
	//t_mesh		cube;

	printf(" => Connection ...");
	img.mlx = mlx_init();
	if (!img.mlx)
	{
		printf(" !! KO !! mlx connection failed\n");
		exit(1);
	}
	printf(" => MLX Connection active\n\n");
	img.win = mlx_new_window(img.mlx, F_SX, F_SY, "Hello World! FHD");
	if (!(img.win))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	// cube = create_cube(0, 0, 0, 100);
	printf(" => Window1 %dx%d \"Hello World! FHD\" OK\n", F_SX, F_SY);
	img.img_ptr = mlx_new_image(img.mlx, F_SX, F_SY);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.ll, &img.endian);
	printf(" => Image info: bpp = %d, line length =%d, endian = %d\n",
		img.bpp, img.ll, img.endian);
	mlx_test(&img);
	printf(" => Test Finished OK\n");
	sleep(3);
	mlx_destroy_window(img.mlx, img.win);
	printf(" => Window Destroy OK\n");
	printf("===============================================\n");
	printf(" => NEW Window %i x %i\n",F_SX * 2, F_SY * 2);

	img.win = mlx_new_window(img.mlx, F_SX * 2, F_SY * 2, "Hello World! FHD 2");

	if (!(img.win))
	{
		printf(" !! KO !!\n");
		return (ERROR);
	}

	printf(" New window OK !!\n");
	img.img_ptr = mlx_new_image(img.mlx, F_SX * 2 , F_SY * 2);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.ll, &img.endian);
	mlx_get_gray(&img);
	mlx_rectangle_menu(&img);
	mlx_loop(img.mlx);

	return (SUCCESS);
}

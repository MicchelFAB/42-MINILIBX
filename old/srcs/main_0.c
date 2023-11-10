/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/05 13:34:50 by antoda-s         ###   ########.fr       */
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

int	main(void)
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
	mlx_loop(img.mlx);

	return (0);
}
